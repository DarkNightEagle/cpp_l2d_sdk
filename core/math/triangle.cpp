#include "triangle.hpp"

bool isPointInTriangle(glm::vec2 pt, const triangleData& inputData)
{
	auto sign = [](const glm::vec2& p1, const glm::vec2& p2, const glm::vec2& p3) {
		return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
		};
	float d1 = sign(pt, inputData.at(0), inputData.at(1));
	float d2 = sign(pt, inputData.at(1), inputData.at(2));
	float d3 = sign(pt, inputData.at(2), inputData.at(0));

	bool hasNeg = (d1 < 0.0f || d2 < 0.0f || d3 < 0.0f);
	bool hasPos = (d1 > 0.0f || d2 > 0.0f || d3 > 0.0f);
	return !(hasNeg && hasPos);
}

bool isPointInTriangle(glm::vec2 pt, const triangleIndices& inputData, MeshData& bindingMesh)
{
	auto sign = [](const glm::vec2& p1, const glm::vec2& p2, const glm::vec2& p3) {
		return static_cast<float>((p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y));
		};
	glm::vec2 p1 = bindingMesh.vertices[inputData[0]];
	glm::vec2 p2 = bindingMesh.vertices[inputData[1]];
	glm::vec2 p3 = bindingMesh.vertices[inputData[2]];

	float d1 = sign(pt, p1, p2);
	float d2 = sign(pt, p2, p3);
	float d3 = sign(pt, p3, p1);
	bool hasNeg = (d1 < 0.0f || d2 < 0.0f || d3 < 0.0f);
	bool hasPos = (d1 > 0.0f || d2 > 0.0f || d3 > 0.0f);
	return !(hasNeg && hasPos);
}

std::array<int, 3> findSurroindingTriangle(glm::vec2 pt, MeshData& bindingMesh)
{
	std::array<int, 3> returnResult{ 0,1,2 };
	for (size_t i = 0; i < bindingMesh.indices.size(); i += 3)
	{
		returnResult[0] = bindingMesh.indices[i];
		returnResult[1] = bindingMesh.indices[i + 1];
		returnResult[2] = bindingMesh.indices[i + 2];
		if (isPointInTriangle(pt, returnResult, bindingMesh)) {
			return returnResult;
		}
	}
	return std::array<int, 3>{0, 0, 0};
}
