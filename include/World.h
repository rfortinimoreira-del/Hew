#pragma once

#include <glm/glm.hpp>
#include <vector>
#include "Block.h"

class World {
public:
    World();
    ~World();
    
    static const int WORLD_WIDTH = 64;
    static const int WORLD_HEIGHT = 64;
    static const int WORLD_DEPTH = 64;
    
    void init();
    void render();
    
    Block* getBlock(int x, int y, int z);
    void setBlock(int x, int y, int z, BlockType type);
    void removeBlock(int x, int y, int z);
    bool isBlockValid(int x, int y, int z);
    
private:
    Block blocks[WORLD_WIDTH][WORLD_HEIGHT][WORLD_DEPTH];
    
    void generateTerrain();
};
