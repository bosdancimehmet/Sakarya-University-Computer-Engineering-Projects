#pragma once
#include <vector>
#include <string>
#include "shape.hpp"
#include "vertexarrayobject.hpp"
#include "shaderprogram.hpp"

class SceneManager
{
public:
    SceneManager();
    
    // Şekil Yönetimi
    void addShape(const std::string& type);
    void deleteSelectedShape();
    void resetSelectedShape();
    
    // Seçim
    void selectShape(int index);
    int getSelectedIndex() const;
    Shape* getSelectedShape(); // Düzenleme için pointer döner
    
    // Dosya İşlemleri
    void saveScene(const std::string& filename);
    void loadScene(const std::string& filename);

    // Çizim
    void render(graf::ShaderProgram& program, const glm::mat4& viewMatrix);

    // Mesh Yükleme (Başlangıçta çağrılacak)
    void loadMeshes();

    // GUI için getter
    std::vector<Shape>& getShapes();

private:
    std::vector<Shape> m_shapes;
    int m_selectedShapeIndex;
    
    // Mesh Pointerları
    graf::VertexArrayObject* m_cubeVAO;
    graf::VertexArrayObject* m_pyramidVAO;
};