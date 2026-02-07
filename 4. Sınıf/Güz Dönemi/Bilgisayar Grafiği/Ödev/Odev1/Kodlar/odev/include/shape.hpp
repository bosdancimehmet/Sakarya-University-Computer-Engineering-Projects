#pragma once
#include <string>
#include <glm/glm.hpp>

struct Shape
{
    std::string type;       // "Küp" veya "Piramit"
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
};