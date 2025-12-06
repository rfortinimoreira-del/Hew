#include "Block.h"

Block::Block() : type(BlockType::EMPTY), position(0), color(1) {}

Block::Block(BlockType t, glm::vec3 pos) : type(t), position(pos) {
    setColor();
}

void Block::setColor() {
    switch (type) {
        case BlockType::STONE:
            color = glm::vec3(0.6f, 0.6f, 0.6f);
            break;
        case BlockType::WOOD:
            color = glm::vec3(0.8f, 0.6f, 0.4f);
            break;
        case BlockType::FLOWER:
            color = glm::vec3(1.0f, 0.7f, 0.9f);
            break;
        case BlockType::PINK_MAGIC:
            color = glm::vec3(1.0f, 0.5f, 0.8f);
            break;
        case BlockType::GLOWING:
            color = glm::vec3(1.0f, 1.0f, 0.6f);
            break;
        default:
            color = glm::vec3(1.0f, 1.0f, 1.0f);
    }
}
