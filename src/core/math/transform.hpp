#pragma once
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
/// @brief 4x4 basis matrix
struct Basis
{
    Basis(glm::mat4 input) :matrix{input} {};
    glm::mat4x4 matrix{1.0};

    glm::vec3 translation() const noexcept 
    {
        return glm::vec3(matrix[3]);
    }
    glm::vec2 scale() const noexcept 
    {
        return glm::vec2{
        glm::length(glm::vec3(matrix[0])),
        glm::length(glm::vec3(matrix[1]))
        };
    }
};

struct Transform {
public:
glm::vec3 translation{0.0,0.0,0.0};
glm::vec3 rotation{0.0,0.0,.0};
glm::vec2 scale{1.0,1.0};
Transform operator+(const Transform& other) const noexcept 
{
    Transform tnew;
    tnew.translation = this->translation+other.translation;
    tnew.rotation = this->rotation+other.rotation;
    tnew.scale = this->scale*other.scale;
    return tnew;
}
Basis matrix() {
    return Basis{glm::translate(glm::mat4{1.0f},translation)*
glm::rotate(glm::mat4{1.0f},rotation.z,glm::vec3{0.0f,0.0f,1.0f})*
glm::rotate(glm::mat4{1.0f},rotation.y,glm::vec3{0.0f,1.0f,0.0f})*
glm::rotate(glm::mat4{1.0f},rotation.x,glm::vec3{1.0f,0.0f,0.0f})*
glm::scale(glm::mat4(1.0f),glm::vec3(scale.x,scale.y,1.0))
};}

void clear() {
    translation = glm::vec3(0.0f);
    rotation = glm::vec3(0.0f);
    scale = glm::vec2(1.0f,1.0f);
}

void onSerialize()
{
    
};
void onDeserialize()
{

};
};