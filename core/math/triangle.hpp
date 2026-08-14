#pragma once
#include <glm/vec2.hpp>
#include <stdint.h>
#include <array>
#include <vector>
#include "../meshdata.hpp"
typedef std::array<glm::vec2, 3> triangleData;
typedef std::array<int, 3> triangleIndices;
bool isPointInTriangle(glm::vec2 pt, const triangleData& inputData);
bool isPointInTriangle(glm::vec2 pt, const  triangleIndices& inputData,MeshData& bindingMesh);
std::array<int, 3> findSurroindingTriangle(glm::vec2 pt, MeshData& bindingMesh);