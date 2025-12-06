#pragma once

#include <glm/glm.hpp>
#include "World.h"

struct RaycastHit {
    bool hit;
    glm::vec3 hitPosition;
    glm::vec3 hitBlockPos;
    glm::vec3 normalFace;
    glm::vec3 adjacentBlockPos; // Para colocar novo bloco
};

class Raycaster {
public:
    Raycaster();
    
    static RaycastHit raycast(glm::vec3 origin, glm::vec3 direction, World* world, float maxDistance = 100.0f);
    
private:
    static bool isBlockSolid(World* world, int x, int y, int z);
};
