#ifndef TRIG_HPP
#define TRIG_HPP
#include <vec2.hpp>
#include <vec3.hpp>
#include <array>
#include <geometric.hpp>
#include <vector>
namespace l2d_cpp
{
	
	// функция для проверки попадания точки в треугольник. (см. counter-clockwise function, ориентированная площадь. Формула строит два вектора с началом в точке p3. Знак финального числа показывает, в какую сторону нужно повернуть вектор A(первый), чтобы кратчайшим путем дойти до вектора B(второй) 
	// результат >0 точки расположены против часовой стрелки. Точка p2 находится слева от направленной прямой p3->p1
	// результат <0 - точки расположены по часовой стрелке. Точка p2 находится справа от направленной прямой p3->p1
	// результат 0 - все точки лежат на одной прямой 
	const float inline sign(const glm::vec2& p1, const glm::vec2& p2, const glm::vec2& p3)
	{
		return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
	}
	/// 2d- треугольник / 2d triangle
	struct Triangle {
		glm::vec2 p1{0.0f, 0.0f};
		glm::vec2 p2{0.0f, 0.0f};
		glm::vec2 p3{0.0f, 0.0f};
		/// @brief Function to find barycentric of triangle/функция для поиска геометрического центра треугольника
		/// @param point input point to check
		/// @return 
		glm::vec3 barycentric(const glm::vec2& point)
		{
			glm::vec2 v1 = p2 - p1;
			glm::vec2 v2 = p3 - p1;
			glm::vec2 v3 = point - p1;
			float den = v1.x * v2.y - v2.x * v1.y;
			float v = (v3.x * v2.y - v2.x * v3.y) / den;
			float w = (v1.x * v3.y - v3.x * v1.y) / den;

			return glm::vec3(1.0 - v - w, v, w);

		}
		const bool contains(const glm::vec2& inputPoint)
		{
			
			float d1 = l2d_cpp::sign(inputPoint, p1, p2);
			float d2 = l2d_cpp::sign(inputPoint, p2, p3);
			float d3 = l2d_cpp::sign(inputPoint, p3, p1);
			return !((d1 < 0 || d2 < 0 || d3 < 0) && (d1 > 0 || d2 > 0 || d3 > 0));
		}
		std::array<size_t,2>  findClosest2(glm::vec2& point, std::vector<glm::vec2>& mesh) {
			size_t p1 = std::numeric_limits<size_t>::max();
			size_t p2 = std::numeric_limits<size_t>::max();
			float closestDist = std::numeric_limits<float>::max();
			for (auto it = mesh.begin(); it != mesh.end(); it++)
			{
				if (glm::distance(point, *it) < closestDist)
				{
					p2 = p1;
					p1 = it - mesh.begin();
				}
			}
			return std::array<size_t, 2>{p1, p2};
		}
		size_t findClosest(glm::vec2& point, std::vector<glm::vec2>& mesh)
		{
			size_t p1 = std::numeric_limits<size_t>::max();
			float closestDist = std::numeric_limits<float>::max();
			for (auto it = mesh.begin(); it != mesh.end(); it++)
			{
				if (glm::distance(point, *it) < closestDist)
				{
					p1 = it - mesh.begin();
				}
			}
			return p1;
		}
	};
}
#endif 