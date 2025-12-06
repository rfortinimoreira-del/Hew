#!/bin/bash
# Script completo de build para Linux + Windows

echo "🎀 Hubble - Build Completo (Linux + Windows)"
echo "=============================================="
echo ""

set -e

# Cores
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m'

# Função para exibir seções
print_section() {
    echo ""
    echo -e "${YELLOW}→ $1${NC}"
    echo ""
}

# Verificar dependências
print_section "Verificando dependências..."

# Linux dependencies
LINUX_DEPS=("cmake" "make" "g++" "pkg-config")
for dep in "${LINUX_DEPS[@]}"; do
    if ! command -v "$dep" &> /dev/null; then
        echo -e "${RED}❌ $dep não encontrado${NC}"
        exit 1
    fi
done

LIBS=("libglfw3-dev" "libglew-dev" "libglm-dev" "libgl1-mesa-dev")
for lib in "${LIBS[@]}"; do
    if dpkg -l | grep -q "^ii.*$lib"; then
        echo -e "${GREEN}✓ $lib${NC}"
    else
        echo -e "${RED}✗ $lib (não instalada)${NC}"
        echo "Instale com: sudo apt-get install $lib"
    fi
done

# Windows compiler
if ! command -v x86_64-w64-mingw32-g++ &> /dev/null; then
    echo -e "${YELLOW}⚠️  MinGW-w64 não encontrado - pulando build Windows${NC}"
    BUILD_WINDOWS=0
else
    echo -e "${GREEN}✓ MinGW-w64 encontrado${NC}"
    BUILD_WINDOWS=1
fi

# Compilar Linux
print_section "Compilando para Linux..."

if [ -d "build" ]; then
    rm -rf build
fi

mkdir -p build
cd build
cmake .. >/dev/null 2>&1
make -j$(nproc) >/dev/null 2>&1

if [ -f "hubble" ]; then
    echo -e "${GREEN}✅ Executável Linux criado${NC}"
    ls -lh hubble
else
    echo -e "${RED}❌ Erro ao compilar para Linux${NC}"
    exit 1
fi

cd ..

# Compilar Windows
if [ $BUILD_WINDOWS -eq 1 ]; then
    print_section "Compilando para Windows..."
    
    bash build-windows-portable.sh >/dev/null 2>&1
    
    if [ -f "windows/hubble.exe" ]; then
        echo -e "${GREEN}✅ Executável Windows criado${NC}"
        ls -lh windows/hubble.exe
    else
        echo -e "${RED}❌ Erro ao compilar para Windows${NC}"
    fi
fi

# Criar pacote Windows
print_section "Criando pacote de distribuição..."

bash package-windows.sh >/dev/null 2>&1

if [ -f "Hubble-Windows-x64.zip" ]; then
    echo -e "${GREEN}✅ Pacote Windows criado${NC}"
    ls -lh Hubble-Windows-x64.zip
fi

# Sumário final
print_section "📊 Sumário do Build"

echo "Build Options:"
echo "  Linux: ✅ build/hubble"
if [ $BUILD_WINDOWS -eq 1 ]; then
    echo "  Windows: ✅ windows/hubble.exe"
    echo "  Windows ZIP: ✅ Hubble-Windows-x64.zip"
else
    echo "  Windows: ❌ (MinGW-w64 não instalado)"
fi

echo ""
echo -e "${GREEN}✨ Build concluído com sucesso!${NC}"
echo ""
echo "Próximos passos:"
echo "  1. Testar a versão Linux: ./build/hubble"
echo "  2. Distribuir Hubble-Windows-x64.zip para Windows"
echo ""
