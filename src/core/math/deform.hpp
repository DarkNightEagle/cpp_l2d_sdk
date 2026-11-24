#pragma once 
#include <glm/vec2.hpp>
#include <vector>
class IDeformable {
    public:
    const std::vector<glm::vec2> basePoints();
    std::vector<glm::vec2> deformPoints();
    
};