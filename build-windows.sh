#!/bin/bash
# Script para compilar Hubble para Windows usando MinGW-w64

echo "🎀 Hubble - Build Windows x64"
echo "================================"

# Cores para output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Verificar se MinGW está instalado
if ! command -v x86_64-w64-mingw32-g++ &> /dev/null; then
    echo -e "${RED}❌ MinGW-w64 não encontrado${NC}"
    echo "Instale com: sudo apt-get install mingw-w64"
    exit 1
fi

echo -e "${GREEN}✅ MinGW-w64 encontrado${NC}"

# Criar diretório de build para Windows
BUILD_DIR="build-windows"
if [ -d "$BUILD_DIR" ]; then
    echo "Removendo build anterior..."
    rm -rf "$BUILD_DIR"
fi

mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

echo -e "${YELLOW}📦 Configurando CMake para Windows...${NC}"

# Configurar CMake com compilação cruzada
cmake -DCMAKE_TOOLCHAIN_FILE=../Toolchain-mingw-w64-x86_64.cmake \
      -DCMAKE_BUILD_TYPE=Release \
      -DBUILD_SHARED_LIBS=OFF \
      .. 2>&1 | grep -v "Skipping"

if [ $? -ne 0 ]; then
    echo -e "${RED}❌ CMake falhou${NC}"
    exit 1
fi

echo -e "${YELLOW}🔨 Compilando...${NC}"
make -j$(nproc) 2>&1

if [ $? -ne 0 ]; then
    echo -e "${RED}❌ Compilação falhou${NC}"
    exit 1
fi

echo ""
echo -e "${GREEN}✅ Build Windows concluído com sucesso!${NC}"
echo ""

# Criar pasta Windows se não existir
if [ ! -d "../windows" ]; then
    mkdir -p ../windows
fi

# Copiar executável
if [ -f "hubble.exe" ]; then
    cp hubble.exe ../windows/
    echo -e "${GREEN}✅ Executável copiado para: ../windows/hubble.exe${NC}"
else
    echo -e "${YELLOW}⚠️ Executável não encontrado em build-windows/${NC}"
fi

echo ""
echo "📂 Conteúdo da pasta Windows:"
ls -lh ../windows/

echo ""
echo "✨ Pronto para distribuição!"
