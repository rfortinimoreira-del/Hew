#include "World.h"
#include <glm/glm.hpp>

World::World() {
    // Inicializar todos os blocos como EMPTY
    for (int x = 0; x < WORLD_WIDTH; x++) {
        for (int y = 0; y < WORLD_HEIGHT; y++) {
            for (int z = 0; z < WORLD_DEPTH; z++) {
                blocks[x][y][z] = Block(BlockType::EMPTY, glm::vec3(x, y, z));
            }
        }
    }
}

World::~World() {
}

void World::init() {
    generateTerrain();
}

void World::generateTerrain() {
    // Criar um terreno básico
    for (int x = 0; x < WORLD_WIDTH; x++) {
        for (int z = 0; z < WORLD_DEPTH; z++) {
            // Camadas de pedra na base
            for (int y = 0; y < 5; y++) {
                blocks[x][y][z] = Block(BlockType::STONE, glm::vec3(x, y, z));
            }
            // Camada de grama/madeira
            blocks[x][5][z] = Block(BlockType::WOOD, glm::vec3(x, 5, z));
            
            // Flores aleatórias
            if ((x + z) % 8 == 0 && x > 10 && x < 50 && z > 10 && z < 50) {
                blocks[x][6][z] = Block(BlockType::FLOWER, glm::vec3(x, 6, z));
            }
        }
    }
    
    // Criar estrutura inicial (base para castelo)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 3; k++) {
                blocks[32 + i][6 + k][32 + j] = Block(BlockType::PINK_MAGIC, glm::vec3(32 + i, 6 + k, 32 + j));
            }
        }
    }
}

void World::render() {
    // Renderizar será feito no Renderer
}

Block* World::getBlock(int x, int y, int z) {
    if (isBlockValid(x, y, z)) {
        return &blocks[x][y][z];
    }
    return nullptr;
}

void World::setBlock(int x, int y, int z, BlockType type) {
    if (isBlockValid(x, y, z)) {
        blocks[x][y][z] = Block(type, glm::vec3(x, y, z));
    }
}

void World::removeBlock(int x, int y, int z) {
    if (isBlockValid(x, y, z)) {
        blocks[x][y][z] = Block(BlockType::EMPTY, glm::vec3(x, y, z));
    }
}

bool World::isBlockValid(int x, int y, int z) {
    return x >= 0 && x < WORLD_WIDTH &&
           y >= 0 && y < WORLD_HEIGHT &&
           z >= 0 && z < WORLD_DEPTH;
}
