#pragma once

#include <glm/vec2.hpp>
#include <vector>
struct MeshData {
	std::vector<glm::vec2> vertices;
    std::vector<glm::vec2> uvs;
    std::vector<uint16_t> indices;
    glm::vec2 origin{ 0.0f,0.0f };
    std::vector<std::vector<float>> gridAxes;
};