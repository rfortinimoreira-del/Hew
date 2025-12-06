# 🎀 Hubble - Jogo 3D Minimalista em Voxel

Um jogo mágico e fofinho onde você explora uma ilha flutuante e constrói castelos com blocos!

## ✨ Status do Projeto

✅ **Completo e Funcional!**

- Renderização 3D com OpenGL
- Sistema de blocos funcional
- Mecânicas de construção (colocar/remover)
- Câmera FPS com controles fluidos
- Input system completo
- Raycasting para seleção precisa de blocos

## 🚀 Como Executar

### 1. Instalar Dependências
```bash
sudo apt-get update
sudo apt-get install -y libglfw3-dev libglew-dev libglm-dev libgl1-mesa-dev cmake
```

### 2. Compilar
```bash
cd /workspaces/Hew
./setup.sh
```

Ou manualmente:
```bash
mkdir -p build
cd build
cmake ..
make
```

### 3. Executar
```bash
cd build
./hubble
```

## 🎮 Controles

| Tecla | Ação |
|-------|------|
| **WASD** | Mover |
| **ESPAÇO** | Subir |
| **SHIFT** | Descer |
| **Mouse** | Olhar ao redor |
| **Clique Esquerdo** | Colocar bloco |
| **Clique Direito** | Remover bloco |
| **1** | Bloco: Pedra |
| **2** | Bloco: Madeira |
| **3** | Bloco: Flor |
| **4** | Bloco: Mágico Rosa |
| **5** | Bloco: Brilhante |
| **ESC** | Sair |

## 🧱 Blocos Disponíveis

| Número | Nome | Cor | Descrição |
|--------|------|-----|-----------|
| 1 | Pedra | Cinza | Base sólida |
| 2 | Madeira | Marrom claro | Natural e caloroso |
| 3 | Flor | Rosa fofo | Decoração |
| 4 | Mágico Rosa | Pink | Construção mágica |
| 5 | Brilhante | Amarelo | Especial e luminoso |

## 🏗️ Arquitetura

```
src/
├── main.cpp           # Loop principal + input handling
├── Renderer.cpp       # Renderização OpenGL
├── World.cpp          # Sistema de mundo (grid 3D)
├── Cube.cpp           # Renderização de cubos individuais
├── Camera.cpp         # Câmera FPS
├── Player.cpp         # Entidade jogadora
├── Block.cpp          # Sistema de blocos
├── Shader.cpp         # Compilação de shaders
├── InputManager.cpp   # Sistema de entrada unificado
├── Raycaster.cpp      # Raycasting para seleção
└── GameState.cpp      # Estado global do jogo

include/
├── *.h               # Headers correspondentes
└── (arquitetura espelhada)

assets/
├── vertex.glsl       # Shader de vértice
└── fragment.glsl     # Shader de fragmento
```

## 📊 Especificações

- **Linguagem**: C++17
- **Graphics API**: OpenGL 3.3 Core Profile
- **Dependências**: GLFW3, GLEW, GLM
- **Resolução**: 1920×1080
- **FPS**: 60 (V-Sync ativado)
- **Tamanho do Mundo**: 64×64×64 blocos

## 🔧 Próximas Features

- [ ] Personagem visível (Hubble com cabelo rosa/lilás)
- [ ] Criatura Fofoluz (bola de luz mágica que segue)
- [ ] Sistema de física e gravidade
- [ ] Colisões com blocos
- [ ] Partículas mágicas
- [ ] Sons e música ambiente
- [ ] Menu principal
- [ ] Sistema de progresso (castelo)
- [ ] Múltiplos biomas
- [ ] Otimização com chunk culling

---

**Feito com 💕 para fãs de mundos mágicos!**

*Versão 1.0 - Dezembro 2025*
