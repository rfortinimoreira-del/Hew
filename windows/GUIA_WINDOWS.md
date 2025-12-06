# 🎀 Hubble - Guia Windows

## 📥 Instalação

### Opção 1: Instalador (Recomendado)
1. Baixe `Hubble-Windows-x64.zip`
2. Extraia em qualquer pasta
3. Execute `install.bat` como administrador
4. O jogo será instalado em `C:\Program Files\Hubble`
5. Procure por "Hubble" no Menu Iniciar

### Opção 2: Portável (Sem Instalação)
1. Baixe `Hubble-Windows-x64.zip`
2. Extraia em qualquer pasta
3. Execute `run.bat` ou clique duplo em `hubble.exe`

## 🎮 Controles Rápidos

| Ação | Tecla |
|------|-------|
| Mover para frente | W |
| Mover para trás | S |
| Mover esquerda | A |
| Mover direita | D |
| Subir | Espaço |
| Descer | Shift |
| Olhar ao redor | Mouse |
| Colocar bloco | Clique Esquerdo |
| Remover bloco | Clique Direito |
| Selecionar Pedra | 1 |
| Selecionar Madeira | 2 |
| Selecionar Flor | 3 |
| Selecionar Bloco Mágico | 4 |
| Selecionar Bloco Brilhante | 5 |
| Sair | ESC |

## 🎨 Tipos de Blocos

1. **Pedra** - Bloco básico cinza
2. **Madeira** - Bloco natural marrom
3. **Flor** - Bloco cosmético rosa
4. **Bloco Mágico** - Rosa brilhante
5. **Bloco Brilhante** - Amarelo luminoso

## 🔧 Solução de Problemas

### "O jogo não inicia"
- Certifique-se de que a pasta `assets` está na mesma pasta que `hubble.exe`
- Seu computador pode não ter OpenGL 3.3 habilitado
- Tente atualizar os drivers da placa gráfica

### "Erro ao instalar"
- Execute `install.bat` como administrador
- Use a pasta Program Files ou outra com permissões de escrita
- Se não conseguir instalar, use a versão portável

### "Performance baixa"
- Feche outros programas
- Reduz o tamanho da janela
- Atualize os drivers da GPU
- O mundo é pequeno (64x64x64), então há limite de performance

### "Não consegue ver os blocos"
- Certifique-se de que os shaders estão em `assets/`
- Tente mover a câmera (WASD)
- Verifique se o OpenGL está funcionando no seu sistema

## 💾 Dados do Jogo

O jogo não salva dados automaticamente. Cada vez que inicia, o mundo é regenerado.

## 🌐 Requisitos Mínimos

- **Windows**: Windows 7 SP1 ou superior
- **GPU**: Placa gráfica com OpenGL 3.3
- **RAM**: 512 MB
- **Disco**: 100 MB

## 🌟 Dicas de Gameplay

1. **Exploração**: Use WASD para se mover e descobrir o mundo
2. **Construção**: Aponte para o chão/paredes e clique esquerdo para colocar
3. **Destruição**: Clique direito para remover blocos indesejados
4. **Criatividade**: Misture diferentes tipos de blocos para criar designs interessantes
5. **Castelo**: Desafio: Construa um castelo completo!

## 📝 Notas Técnicas

- Linguagem: C++17
- Graphics API: OpenGL 3.3
- Compilador: MinGW-w64 (x86_64)
- Resolução: 1920x1080 (ajustável)

## 🐛 Reportar Bugs

Se encontrar algum problema, reporte em:
https://github.com/rfortinimoreira-del/Hew/issues

## 📦 Conteúdo do Pacote

```
windows/
├── hubble.exe          - Executável do jogo
├── install.bat         - Script de instalação
├── run.bat             - Script de execução rápida
├── README.txt          - Instruções básicas
├── VERSION.txt         - Informações de versão
└── assets/
    ├── vertex.glsl     - Shader de vértice
    └── fragment.glsl   - Shader de fragmento
```

## ✨ Créditos

Desenvolvido com C++ e OpenGL

Divirta-se! 🎮
