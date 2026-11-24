/**
    Inochi2D Math Primitives

    Copyright:
        Copyright © 2020-2025, Inochi2D Project

    License:
        $(LINK2 https://github.com/Inochi2D/inochi2d/blob/main/LICENSE, BSD 2-clause License)

    Authors:
        Luna Nielsen
        Hoshino Lina

    Rewritten to C++ by: DarkNightEagle
*/

#ifndef __PACKAGE_HPP__
#define __PACKAGE_HPP__
#include <glm/vec2.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec2.hpp>
#include <numeric>
#include <cmath>
class Camera
{
protected:
    glm::vec2 size;

    virtual glm::mat4 matrix() { return glm::mat4{}; }
    virtual void update() {};

public:
    Camera() { size = glm::vec2{1.0, 1.0}; };
};

class Camera2D : public Camera
{
private:
    glm::mat4 projection;

public:
    glm::vec2 position{0.0};
    float rotation{0.0f};
    float scale{1.0f};
    glm::vec2 inline centerOffset() {return size/2.0f;};
    glm::mat4 matrix() override;
    void update() override;
};
#endif //__PACKAGE_HPP__