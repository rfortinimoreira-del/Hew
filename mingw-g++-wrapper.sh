#!/bin/bash
# Wrapper para x86_64-w64-mingw32-g++ que remove -isystem /usr/include
# Expande arquivos de resposta (@file) e filtra

# Processar argumentos, expandindo arquivos de resposta
expanded_args=()

for arg in "$@"; do
    if [[ "$arg" == @* ]]; then
        # Arquivo de resposta: ler e expandir, removendo "-isystem /usr/include"
        rsp_file="${arg:1}"  # Remove o @
        if [ -f "$rsp_file" ]; then
            # Usar sed para remover "-isystem /usr/include" do arquivo
            # e converter em array de argumentos
            filtered_content=$(sed 's|-isystem /usr/include||g' "$rsp_file")
            # Separar por espaços (cuidado com aspas)
            eval "rsp_args=($filtered_content)"
            for rsp_arg in "${rsp_args[@]}"; do
                [ -n "$rsp_arg" ] && expanded_args+=("$rsp_arg")
            done
        fi
    else
        # Argumento normal (não é arquivo de resposta)
        expanded_args+=("$arg")
    fi
done

# Executar o compilador MinGW com argumentos filtrados
exec /usr/bin/x86_64-w64-mingw32-g++ "${expanded_args[@]}"
