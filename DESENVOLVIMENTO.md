# 🎀 Hubble - Jogo 3D Minimalista em Voxel

Um jogo mágico e fofinho onde você explora uma ilha flutuante e constrói castelos com blocos!

## ✨ Recursos Implementados

### ✅ Renderização 3D Completa
- Renderização de cubos com OpenGL 3.3
- Grid 3D de 64×64×64 blocos
- Iluminação simples e bonita
- Céu azul pastel

### ✅ Sistema de Blocos
- 5 tipos de blocos diferentes:
  - 🪨 Pedra (cinza)
  - 🪵 Madeira (marrom claro)
  - 🌸 Flor (rosa fofo)
  - 💗 Bloco Mágico Rosa (rosa mágico)
  - ✨ Bloco Brilhante (amarelo brilhante)

### ✅ Mecânicas de Construção
- **Clique Esquerdo**: Colocar blocos
- **Clique Direito**: Remover blocos
- **1-5**: Selecionar tipo de bloco
- Raycasting para seleção precisa

### ✅ Câmera e Controles
- **WASD**: Movimento horizontal
- **ESPAÇO**: Subir
- **SHIFT**: Descer
- **Mouse**: Olhar ao redor
- **ESC**: Sair do jogo

### ✅ Geração de Terreno
- Terreno procedural com múltiplas camadas
- Base de pedra
- Plataforma de madeira
- Flores decorativas
- Estrutura base para castelo em rosa mágico

## 🚀 Como Compilar e Executar

### Pré-requisitos
```bash
sudo apt-get install libglfw3-dev libglew-dev libglm-dev cmake
```

### Build
```bash
cd /workspaces/Hew
mkdir -p build
cd build
cmake ..
make
```

### Executar
```bash
./hubble
```

## 📁 Estrutura do Projeto

```
Hubble/
├── src/
│   ├── main.cpp          # Loop principal do jogo
│   ├── Renderer.cpp      # Renderização OpenGL
│   ├── World.cpp         # Sistema de mundo e blocos
│   ├── Player.cpp        # Controle da jogadora
│   ├── Camera.cpp        # Câmera FPS
│   ├── Block.cpp         # Definições de blocos
│   ├── Cube.cpp          # Renderização de cubos
│   ├── Shader.cpp        # Compilação de shaders
│   ├── InputManager.cpp  # Sistema de entrada
│   ├── Raycaster.cpp     # Detecção de cliques
│   └── GameState.cpp     # Estado global do jogo
├── include/              # Headers das classes
├── assets/
│   ├── vertex.glsl       # Shader de vértice
│   └── fragment.glsl     # Shader de fragmento
├── CMakeLists.txt        # Configuração CMake
└── README.md
```

## 🎮 Gameplay Básico

1. **Explorar**: Use WASD para se mover pela ilha
2. **Construir**: Selecione um bloco (1-5) e clique para colocar
3. **Destruir**: Clique direito para remover blocos
4. **Criar**: Construa castelos, torres e estruturas mágicas!

## 🔧 Próximas Features a Implementar

- [ ] Personagem visível (Hubble)
- [ ] Criatura Fofoluz (bola de luz mágica)
- [ ] Sistema de física (gravidade, colisões)
- [ ] Partículas mágicas
- [ ] Sons e música
- [ ] Menu principal
- [ ] Sistema de progresso (conquistar partes do castelo)
- [ ] Efeitos especiais para blocos brilhantes
- [ ] Limite de blocos que podem ser colocados
- [ ] Sistema de câmera de modo construção

## 💡 Dicas de Desenvolvimento

### Adicionar Novo Tipo de Bloco

1. Adicione ao enum `BlockType` em `include/Block.h`
2. Defina a cor em `Block::setColor()` em `src/Block.cpp`
3. Use 1-5 para selecionar diferentes tipos

### Otimização de Renderização

O renderizador atual desenha cada bloco individualmente. Para melhor performance em mundos maiores:
- Implementar frustum culling
- Usar instancing de cubos
- Criar chunks de blocos
- Usar LOD (Level of Detail)

### Estender o Mundo

Para aumentar o tamanho do mundo, modifique as constantes em `include/World.h`:
```cpp
static const int WORLD_WIDTH = 128;   // Aumentar de 64
static const int WORLD_HEIGHT = 128;  // Aumentar de 64
static const int WORLD_DEPTH = 128;   // Aumentar de 64
```

## 📝 Notas Técnicas

- Linguagem: C++17
- Graphics API: OpenGL 3.3
- Dependências: GLFW3, GLEW, GLM
- Resolução: 1920×1080
- FPS: 60 (V-Sync habilitado)

---

**Feito com 💕 para fãs de mundos mágicos!**
