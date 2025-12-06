# Hubble - Jogo 3D Minimalista em Voxel

Um jogo mágico e fofinho onde você explora uma ilha flutuante e constrói castelos.

## 🎮 Como Compilar

```bash
mkdir build
cd build
cmake ..
make
./hubble
```

## 📋 Dependências

- GLFW3
- GLEW
- GLM
- OpenGL 3.3+
- CMake 3.16+

### Instalação no Ubuntu/Debian:

```bash
sudo apt-get install libglfw3-dev libglew-dev libglm-dev
```

## 🕹️ Controles

- **WASD** - Mover
- **Espaço** - Pular
- **Mouse** - Olhar ao redor
- **Clique Esquerdo** - Colocar bloco
- **Clique Direito** - Remover bloco
- **ESC** - Sair

## 🏗️ Estrutura do Projeto

```
Hubble/
├── src/          # Código fonte
├── include/      # Headers
├── assets/       # Texturas, sons, shaders
├── build/        # Diretório de build
└── CMakeLists.txt
```

## 🎨 Blocos Disponíveis

- Pedra (base)
- Madeira (natural)
- Flor (cosmético)
- Bloco Mágico Rosa (construção)
- Bloco Brilhante (especial)

## 📖 Próximas Etapas

- [ ] Renderização de cubos completa
- [ ] Sistema de input para colocar/remover blocos
- [ ] Personagem visível
- [ ] Criatura Fofoluz
- [ ] Efeitos de partículas
- [ ] Sons e música
- [ ] Menu principal
- [ ] Sistema de progresso (construir castelo)
