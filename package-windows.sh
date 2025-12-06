#!/bin/bash
# Script para criar pacote Windows para distribuição

echo "📦 Hubble - Criando pacote Windows para distribuição"
echo "====================================================="

cd "$(dirname "$0")"

# Verificar se existe a pasta windows
if [ ! -d "windows" ]; then
    echo "❌ Pasta 'windows' não encontrada!"
    exit 1
fi

# Criar arquivo ZIP
OUTPUT_FILE="Hubble-Windows-x64.zip"

# Remover ZIP antigo se existir
if [ -f "$OUTPUT_FILE" ]; then
    rm "$OUTPUT_FILE"
    echo "🗑️  Removido ZIP anterior"
fi

# Criar novo ZIP
echo "📦 Empacotando arquivos..."
zip -r "$OUTPUT_FILE" windows/ -q

if [ -f "$OUTPUT_FILE" ]; then
    SIZE=$(du -h "$OUTPUT_FILE" | cut -f1)
    echo ""
    echo "✅ Pacote criado com sucesso!"
    echo ""
    echo "📄 Arquivo: $OUTPUT_FILE"
    echo "📊 Tamanho: $SIZE"
    echo ""
    echo "📂 Conteúdo:"
    unzip -l "$OUTPUT_FILE" | head -20
    echo ""
    echo "✨ Pronto para distribuição!"
else
    echo "❌ Erro ao criar o ZIP"
    exit 1
fi
