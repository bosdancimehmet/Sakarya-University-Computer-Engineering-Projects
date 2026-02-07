#include "../include/scenemanager.hpp" 
#include "meshloader.hpp"
#include "texturemanager.hpp"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>

using json = nlohmann::json;
using namespace std;

SceneManager::SceneManager()
{
    m_selectedShapeIndex = -1;
    m_cubeVAO = nullptr;
    m_pyramidVAO = nullptr;
}

void SceneManager::loadMeshes()
{
    graf::MeshLoader loader;
    m_cubeVAO = loader.loadMeshFromFile("./meshes/cube.mesh");
    m_pyramidVAO = loader.loadMeshFromFile("./meshes/pyramid.mesh");
    
    // Textureları da yükledim
    graf::TextureManager::addTextureFromFile("container.jpg");
    graf::TextureManager::addTextureFromFile("selected.jpg");
}

void SceneManager::addShape(const std::string& type)
{
    Shape newShape;
    newShape.type = type;
    newShape.position = glm::vec3(0.0f);
    newShape.rotation = glm::vec3(0.0f);
    newShape.scale = glm::vec3(1.0f);
    
    m_shapes.push_back(newShape);
    m_selectedShapeIndex = m_shapes.size() - 1; // Yeni ekleneni seç
}

void SceneManager::deleteSelectedShape()
{
    if (m_selectedShapeIndex >= 0 && m_selectedShapeIndex < m_shapes.size())
    {
        m_shapes.erase(m_shapes.begin() + m_selectedShapeIndex);
        
        // Silince index boşa düşmesin
        if(m_shapes.empty()) 
            m_selectedShapeIndex = -1;
        else if(m_selectedShapeIndex >= m_shapes.size()) 
            m_selectedShapeIndex = m_shapes.size() - 1;
    }
}

void SceneManager::resetSelectedShape()
{
    Shape* s = getSelectedShape();
    if(s)
    {
        s->position = glm::vec3(0.0f);
        s->rotation = glm::vec3(0.0f);
        s->scale = glm::vec3(1.0f);
    }
}

void SceneManager::selectShape(int index)
{
    if(index >= 0 && index < m_shapes.size())
        m_selectedShapeIndex = index;
}

int SceneManager::getSelectedIndex() const
{
    return m_selectedShapeIndex;
}

Shape* SceneManager::getSelectedShape()
{
    if (m_selectedShapeIndex >= 0 && m_selectedShapeIndex < m_shapes.size())
        return &m_shapes[m_selectedShapeIndex];
    return nullptr;
}

std::vector<Shape>& SceneManager::getShapes()
{
    return m_shapes;
}

void SceneManager::render(graf::ShaderProgram& program, const glm::mat4& viewMatrix)
{
    for(int i = 0; i < m_shapes.size(); ++i)
    {
        Shape& s = m_shapes[i];

        // Kaplama(doku) Seçimi
        if(i == m_selectedShapeIndex)
            graf::TextureManager::activateTexture("selected.jpg");
        else
            graf::TextureManager::activateTexture("container.jpg");

        // Model Matrisi
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, s.position);
        model = glm::rotate(model, glm::radians(s.rotation.x), glm::vec3(1, 0, 0));
        model = glm::rotate(model, glm::radians(s.rotation.y), glm::vec3(0, 1, 0));
        model = glm::rotate(model, glm::radians(s.rotation.z), glm::vec3(0, 0, 1));
        model = glm::scale(model, s.scale);

        program.setMat4("uTransformationMatrix", viewMatrix * model);

        // Çizim
        if(s.type == "Cube" && m_cubeVAO)
        {
            m_cubeVAO->bind();
            glDrawArrays(GL_TRIANGLES, 0, 36);
            m_cubeVAO->unbind();
        }
        else if(s.type == "Pyramid" && m_pyramidVAO)
        {
            m_pyramidVAO->bind();
            glDrawArrays(GL_TRIANGLES, 0, 18);
            m_pyramidVAO->unbind();
        }
    }
}

void SceneManager::saveScene(const std::string& filename)
{
    json j;
    j["selectedIndex"] = m_selectedShapeIndex;
    
    for(const auto& shape : m_shapes)
    {
        json s;
        s["type"] = shape.type;
        s["pos"] = { shape.position.x, shape.position.y, shape.position.z };
        s["rot"] = { shape.rotation.x, shape.rotation.y, shape.rotation.z };
        s["scl"] = { shape.scale.x, shape.scale.y, shape.scale.z };
        j["shapes"].push_back(s);
    }

    ofstream file(filename);
    if(file.is_open())
    {
        file << j.dump(4);
        file.close();
        cout << "Sahne kaydedildi!" << endl;
    }
}

void SceneManager::loadScene(const std::string& filename)
{
    ifstream file(filename);
    if(file.is_open())
    {
        json j;
        file >> j;

        if(j.contains("selectedIndex"))
            m_selectedShapeIndex = j["selectedIndex"];

        if(j.contains("shapes"))
        {
            m_shapes.clear();
            for(auto& element : j["shapes"])
            {
                Shape s;
                s.type = element["type"];
                s.position = glm::vec3(element["pos"][0], element["pos"][1], element["pos"][2]);
                s.rotation = glm::vec3(element["rot"][0], element["rot"][1], element["rot"][2]);
                s.scale = glm::vec3(element["scl"][0], element["scl"][1], element["scl"][2]);
                m_shapes.push_back(s);
            }
        }
        file.close();
        cout << "Sahne yuklendi!" << endl;
    }
}