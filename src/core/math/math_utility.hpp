#pragma once
#include <glm/glm.hpp>

bool isFinite(const glm::vec3& v) noexcept {
    return !glm::any(glm::isnan(v)) && !glm::any(glm::isinf(v));
}