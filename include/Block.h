#pragma once

#include <glm/glm.hpp>

enum class BlockType {
    EMPTY = 0,
    STONE = 1,
    WOOD = 2,
    FLOWER = 3,
    PINK_MAGIC = 4,
    GLOWING = 5
};

struct Block {
    BlockType type;
    glm::vec3 position;
    glm::vec3 color;
    
    Block();
    Block(BlockType t, glm::vec3 pos);
    
    void setColor();
};
