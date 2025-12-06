#!/bin/bash
# Script de setup rápido para Hubble no Linux

echo "🎀 Hubble - Setup Script"
echo "========================"

# Verificar se temos as dependências
echo "Verificando dependências..."

# Instalar dependências se necessário
if ! dpkg -l | grep -q libglfw3-dev; then
    echo "Instalando GLFW3..."
    sudo apt-get update
    sudo apt-get install -y libglfw3-dev
fi

if ! dpkg -l | grep -q libglew-dev; then
    echo "Instalando GLEW..."
    sudo apt-get install -y libglew-dev
fi

if ! dpkg -l | grep -q libglm-dev; then
    echo "Instalando GLM..."
    sudo apt-get install -y libglm-dev
fi

if ! command -v cmake &> /dev/null; then
    echo "Instalando CMake..."
    sudo apt-get install -y cmake
fi

echo ""
echo "✅ Dependências verificadas!"
echo ""

# Criar e compilar
echo "Compilando Hubble..."
cd "$(dirname "$0")"

if [ -d build ]; then
    echo "Removendo build anterior..."
    rm -rf build
fi

mkdir -p build
cd build

cmake .. || { echo "❌ CMake falhou"; exit 1; }
make || { echo "❌ Make falhou"; exit 1; }

echo ""
echo "✅ Compilação concluída com sucesso!"
echo ""
echo "Para executar o jogo:"
echo "  ./hubble"
echo ""
