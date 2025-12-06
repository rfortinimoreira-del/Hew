# 📖 Guia Completo - Hubble

## 🎮 Primeira Vez Jogando?

### Passos Iniciais

1. **Iniciar o jogo**
   ```bash
   ./hubble
   ```
   Você verá a ilha flutuante com um mundo voxel inteiro!

2. **Explorar**
   - Use **WASD** para se mover
   - Mova o **mouse** para olhar ao redor
   - Use **ESPAÇO** para subir
   - Use **SHIFT** para descer

3. **Construir**
   - Pressione **1-5** para selecionar um tipo de bloco
   - Aponte com o mouse para um local
   - **Clique Esquerdo** para colocar
   - **Clique Direito** para remover

### Dica de Ouro 💡
Comece construindo uma pequena casa ao lado da estrutura rosa no centro da ilha!

---

## 🧱 Sistemas de Blocos

### Tipos de Bloco

```
1 - PEDRA (Cinza)
    └─ Ideal para: Alicerces, bases, estruturas
    └─ Propriedades: Sólida, resistente

2 - MADEIRA (Marrom claro)
    └─ Ideal para: Paredes, telhados, decoração
    └─ Propriedades: Caloroso, natural

3 - FLOR (Rosa fofo)
    └─ Ideal para: Decoração, jardins
    └─ Propriedades: Cosmético, não-estrutural

4 - BLOCO MÁGICO ROSA (Pink intenso)
    └─ Ideal para: Castelos, estruturas mágicas
    └─ Propriedades: Espetacular, temático

5 - BLOCO BRILHANTE (Amarelo)
    └─ Ideal para: Destaques, iluminação
    └─ Propriedades: Especial, atração visual
```

---

## 🏰 Ideias de Construção

### Projeto 1: Casa Simples (Iniciante)
```
Passos:
1. Selecione PEDRA (1)
2. Crie uma base 5x5 (25 blocos)
3. Coloque MADEIRA (2) no topo para formar paredes
4. Adicione mais MADEIRA para criar teto
5. Deixe um espaço para porta
```

### Projeto 2: Torre (Intermediário)
```
Passos:
1. Crie uma base 3x3
2. Coloque blocos verticalmente (até 10 blocos de altura)
3. Use BLOCO MÁGICO ROSA para destaque
4. Coloque BLOCO BRILHANTE no topo
5. Circunde com FLORES
```

### Projeto 3: Castelo (Avançado)
```
Passos:
1. Planeje no papel (sketch)
2. Crie os alicerces com PEDRA
3. Construa muros com MADEIRA + BLOCO MÁGICO
4. Adicione torres nos cantos com BLOCO BRILHANTE
5. Decore com FLORES
6. Crie um portão/entrada
```

---

## ⚙️ Controles Avançados

### Câmera
- **Mouse**: Olhar ao redor (sensibilidade: 0.1)
- O mouse está sempre centralizado no meio da tela

### Movimento
- **W**: Frente
- **A**: Esquerda
- **S**: Trás
- **D**: Direita
- **ESPAÇO**: Subir (velocidade de construção: 0.15 blocos/frame)
- **SHIFT**: Descer

### Construção
- Aponte com o mouse para um bloco
- A face será iluminada automaticamente
- **Clique Esquerdo**: Coloca ao lado
- **Clique Direito**: Remove

### Seleção de Bloco
- **1**: Pedra
- **2**: Madeira
- **3**: Flor
- **4**: Bloco Mágico Rosa
- **5**: Bloco Brilhante
- **ESC**: Sair do jogo

---

## 🎨 Dicas de Design

### Paleta de Cores
```
- Cinza (Pedra): Sombra, profundidade
- Marrom (Madeira): Calidez, naturalidade
- Rosa (Flor): Detalhes, pontos focais
- Pink (Mágico): Tema, destaque mágico
- Amarelo (Brilhante): Luminosidade, atenção
```

### Padrões Populares
1. **Xadrez**: Alterna cores para efeito visual
2. **Camadas**: Cria profundidade e dimensão
3. **Destaque Central**: Usa Bloco Brilhante como ponto focal
4. **Molduras**: Madeira em volta de Pedra

---

## 📊 Performance & Otimização

### FPS
- O jogo roda a 60 FPS com V-Sync
- Para notar lag, você provavelmente teria 50k+ blocos renderizados

### Limite de Mundo
- **Tamanho**: 64×64×64 blocos
- Você pode construir em qualquer lugar!

### Dicas de Performance
- Remova blocos que não vê mais
- Construa em áreas menores para menor latência
- O raycasting pode usar 1-5% CPU por clique

---

## 🐛 Troubleshooting

### "O jogo não inicia"
```bash
# Verifique as dependências
ldd ./hubble

# Instale novamente
sudo apt-get install libglfw3 libglew2.2 libglm0.9.9
```

### "Muito lento"
- Remova blocos não utilizados
- Reduza a distância de renderização (máximo: 64×64×64)
- Considere desabilitar alguns blocos

### "Mouse preso"
- Pressione **ESC** para sair
- O mouse está sempre desativado (travado ao centro)

---

## 🎯 Objetivos Sugeridos

### Fácil
- [ ] Construir uma casa 5×5
- [ ] Usar todos os 5 tipos de bloco
- [ ] Explorar toda a ilha

### Médio
- [ ] Construir uma torre com 20+ blocos de altura
- [ ] Criar um padrão decorativo (xadrez, etc)
- [ ] Fazer uma estrutura simétrica

### Difícil
- [ ] Construir um castelo completo (torres, muros, portão)
- [ ] Replicar uma estrutura real (Colosseu, Torr Eiffel, etc)
- [ ] Encher 1/4 da ilha com construções

---

## 📚 Referências Técnicas

### Sistema de Iluminação
- Iluminação ambiente: 0.3 (30% de brilho base)
- Normal da face é considerada
- Luz direcional: (1, 1, 1)

### Renderização
- **Câmera**: 45° FOV
- **Distância Perto**: 0.1
- **Distância Longe**: 1000
- **Resolução**: 1920×1080

### Raycasting
- **Distância Máxima**: 100 blocos
- **Passo**: 0.1 (precisão alta)
- **Função**: Detecta face exata para colocação

---

## 🚀 Comandos Úteis

### Re-compilar
```bash
cd /workspaces/Hew/build
make clean && make
```

### Modo Debug
Edite `src/main.cpp` e adicione prints em `InputManager::update()`

### Expandir Mundo
Edite `include/World.h`:
```cpp
static const int WORLD_WIDTH = 128;
static const int WORLD_HEIGHT = 128;
static const int WORLD_DEPTH = 128;
```
Depois recompile!

---

**Divirta-se construindo! 🎀✨**
