#include "Raycaster.h"
#include <glm/glm.hpp>

Raycaster::Raycaster() {}

bool Raycaster::isBlockSolid(World* world, int x, int y, int z) {
    Block* block = world->getBlock(x, y, z);
    if (block == nullptr) return false;
    return block->type != BlockType::EMPTY;
}

RaycastHit Raycaster::raycast(glm::vec3 origin, glm::vec3 direction, World* world, float maxDistance) {
    RaycastHit hit;
    hit.hit = false;
    
    direction = glm::normalize(direction);
    float distance = 0.0f;
    float step = 0.1f;
    
    glm::vec3 current = origin;
    glm::vec3 lastValid = origin;
    
    while (distance < maxDistance) {
        current = origin + direction * distance;
        
        int x = static_cast<int>(glm::round(current.x));
        int y = static_cast<int>(glm::round(current.y));
        int z = static_cast<int>(glm::round(current.z));
        
        if (!world->isBlockValid(x, y, z)) {
            distance += step;
            continue;
        }
        
        if (isBlockSolid(world, x, y, z)) {
            hit.hit = true;
            hit.hitBlockPos = glm::vec3(x, y, z);
            hit.hitPosition = current;
            
            // Calcular normal da face
            glm::vec3 lastCheckPos = origin + direction * (distance - step * 0.5f);
            glm::vec3 diff = current - lastCheckPos;
            
            if (glm::abs(diff.x) > glm::abs(diff.y) && glm::abs(diff.x) > glm::abs(diff.z)) {
                hit.normalFace = glm::vec3(diff.x > 0 ? 1 : -1, 0, 0);
            } else if (glm::abs(diff.y) > glm::abs(diff.z)) {
                hit.normalFace = glm::vec3(0, diff.y > 0 ? 1 : -1, 0);
            } else {
                hit.normalFace = glm::vec3(0, 0, diff.z > 0 ? 1 : -1);
            }
            
            // Posição adjacente para colocar novo bloco
            hit.adjacentBlockPos = hit.hitBlockPos + hit.normalFace;
            
            return hit;
        }
        
        distance += step;
    }
    
    return hit;
}
