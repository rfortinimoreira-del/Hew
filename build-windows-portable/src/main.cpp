#include "Renderer.h"
#include "World.h"
#include "Player.h"
#include "InputManager.h"
#include "Raycaster.h"
#include "GameState.h"
#include "Cube.h"
#include <GLFW/glfw3.h>
#include <iostream>

// Variáveis globais
Renderer* g_renderer = nullptr;
World* g_world = nullptr;
Player* g_player = nullptr;

int main() {
    // Inicializar renderer
    g_renderer = new Renderer();
    g_renderer->init();
    
    // Inicializar input manager
    InputManager::init(g_renderer->getWindow());
    
    // Inicializar mundo
    g_world = new World();
    g_world->init();
    
    // Inicializar jogadora
    g_player = new Player();
    
    // Configurar posição inicial da câmera
    g_player->getCamera().setPosition(glm::vec3(32, 30, 32));
    
    std::cout << "=== Hubble - Jogo de Construção Mágico ===" << std::endl;
    std::cout << "Controles:" << std::endl;
    std::cout << "  WASD - Mover" << std::endl;
    std::cout << "  ESPAÇO - Subir" << std::endl;
    std::cout << "  SHIFT - Descer" << std::endl;
    std::cout << "  Mouse - Olhar" << std::endl;
    std::cout << "  Clique Esquerdo - Colocar bloco" << std::endl;
    std::cout << "  Clique Direito - Remover bloco" << std::endl;
    std::cout << "  1-5 - Selecionar tipo de bloco" << std::endl;
    std::cout << "  ESC - Sair" << std::endl;
    
    // Loop principal
    double lastTime = glfwGetTime();
    bool lastLeftClick = false;
    bool lastRightClick = false;
    
    while (!g_renderer->shouldClose()) {
        double currentTime = glfwGetTime();
        double deltaTime = currentTime - lastTime;
        lastTime = currentTime;
        
        // Processar entrada
        glfwPollEvents();
        InputManager::update();
        
        // Verificar ESC para sair
        if (InputManager::isKeyPressed(GLFW_KEY_ESCAPE)) {
            g_renderer->setWindowShouldClose(true);
        }
        
        // Processar cliques do mouse para colocar/remover blocos
        Raycaster raycaster;
        RaycastHit hit = raycaster.raycast(
            g_player->getCamera().getPosition(),
            g_player->getCamera().getDirection(),
            g_world,
            100.0f
        );
        
        // Clique esquerdo - colocar bloco
        bool currentLeftClick = InputManager::isMouseButtonJustPressed(GLFW_MOUSE_BUTTON_LEFT);
        if (currentLeftClick && !lastLeftClick && hit.hit) {
            glm::vec3 posToPlace = hit.adjacentBlockPos;
            if (g_world->isBlockValid(posToPlace.x, posToPlace.y, posToPlace.z)) {
                BlockType blockType = static_cast<BlockType>(GameState::selectedBlockType);
                g_world->setBlock(posToPlace.x, posToPlace.y, posToPlace.z, blockType);
            }
        }
        lastLeftClick = currentLeftClick;
        
        // Clique direito - remover bloco
        bool currentRightClick = InputManager::isMouseButtonJustPressed(GLFW_MOUSE_BUTTON_RIGHT);
        if (currentRightClick && !lastRightClick && hit.hit) {
            glm::vec3 posToRemove = hit.hitBlockPos;
            if (g_world->isBlockValid(posToRemove.x, posToRemove.y, posToRemove.z)) {
                g_world->removeBlock(posToRemove.x, posToRemove.y, posToRemove.z);
            }
        }
        lastRightClick = currentRightClick;
        
        // Seleção de tipo de bloco com números 1-5
        static int lastSelectedBlock = -1;
        if (InputManager::isKeyJustPressed(GLFW_KEY_1)) {
            GameState::selectedBlockType = static_cast<int>(BlockType::STONE);
            if (lastSelectedBlock != GameState::selectedBlockType) {
                std::cout << "Bloco selecionado: Pedra" << std::endl;
                lastSelectedBlock = GameState::selectedBlockType;
            }
        }
        if (InputManager::isKeyJustPressed(GLFW_KEY_2)) {
            GameState::selectedBlockType = static_cast<int>(BlockType::WOOD);
            if (lastSelectedBlock != GameState::selectedBlockType) {
                std::cout << "Bloco selecionado: Madeira" << std::endl;
                lastSelectedBlock = GameState::selectedBlockType;
            }
        }
        if (InputManager::isKeyJustPressed(GLFW_KEY_3)) {
            GameState::selectedBlockType = static_cast<int>(BlockType::FLOWER);
            if (lastSelectedBlock != GameState::selectedBlockType) {
                std::cout << "Bloco selecionado: Flor" << std::endl;
                lastSelectedBlock = GameState::selectedBlockType;
            }
        }
        if (InputManager::isKeyJustPressed(GLFW_KEY_4)) {
            GameState::selectedBlockType = static_cast<int>(BlockType::PINK_MAGIC);
            if (lastSelectedBlock != GameState::selectedBlockType) {
                std::cout << "Bloco selecionado: Mágico Rosa" << std::endl;
                lastSelectedBlock = GameState::selectedBlockType;
            }
        }
        if (InputManager::isKeyJustPressed(GLFW_KEY_5)) {
            GameState::selectedBlockType = static_cast<int>(BlockType::GLOWING);
            if (lastSelectedBlock != GameState::selectedBlockType) {
                std::cout << "Bloco selecionado: Brilhante" << std::endl;
                lastSelectedBlock = GameState::selectedBlockType;
            }
        }
        
        // Atualizar
        g_player->update();
        
        // Renderizar
        g_renderer->clear();
        g_renderer->render(
            g_world,
            g_player->getCamera().getViewMatrix(),
            g_player->getCamera().getProjectionMatrix()
        );
        g_player->render();
        g_renderer->swapBuffers();
    }
    
    // Cleanup
    Cube::cleanupCubeData();
    delete g_player;
    delete g_world;
    delete g_renderer;
    
    return 0;
}
