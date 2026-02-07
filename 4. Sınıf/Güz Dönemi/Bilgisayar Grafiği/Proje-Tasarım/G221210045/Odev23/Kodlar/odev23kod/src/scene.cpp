#include "scene.hpp"
#include "model.hpp"
#include "shadermanager.hpp"
#include "shaderprogram.hpp"
#include "transform.hpp"
#include "camera.hpp" 
#include <stack>
#include <imgui/imgui.h>
#include <iostream>

namespace graf
{
    int id = 1000; 
    using namespace std;

    Scene::Scene()
    {
        m_root = new SceneObject();
        m_root->m_name = "Root";
        m_selectedObject = m_root;
        m_secondaryViewPort = nullptr;

        // Görselleştirme kutusu Kamerayı temsil etmek için yedek
        m_cameraVisualizer = Model::loadModel("Cube_UnlitTextured");
        m_cameraVisualizer->transform->scale = glm::vec3(0.5f, 0.5f, 0.5f);
    }

    void Scene::drawScene(ViewPort* viewPort)
    {
        stack<SceneObject*> objects;
        objects.push(m_root);

        while(!objects.empty())
        {
            auto next = objects.top();
            objects.pop(); 

            next->transform->updateRotation();
            next->transform->update();
            next->updateChilds();

            //  MODEL ÇİZİMİ
            if(next->getType() == SceneObjectType::Model)
            {
                Model* model = (Model*)next;
                if(model != m_cameraVisualizer) 
                {
                    string shaderName = model->getShaderName();
                    ShaderProgram* program = ShaderManager::getProgram(shaderName);
                    if(program)
                    {
                        program->use();
                        viewPort->actiaveCamera(program);
                        model->draw(program);
                        program->unuse();
                    }
                }
            }
            //  Kamera Görselleştirme
            else if(next->getType() == SceneObjectType::Camera)
            {
                // Eğer bu kamera aktif kamera değilse çizilebilir
                // Ancak ben zaten kameranın içine model koyduğum için (Gövde, Lens vs.)
                // ekstra bir kutu çizmeye gerek yok. Ama garanti olsun diye kalsın.
            }

            for(auto nextChild : next->m_childs)
            {
                objects.push(nextChild);
            }
        }
    }

    void Scene::drawGui()
    {
        id = 1000;

        // --- SOL PANEL: SCENE ---
        ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Once);
        ImGui::SetNextWindowSize(ImVec2(300, 800), ImGuiCond_Once);
        
        ImGui::Begin("Scene");
            if(ImGui::TreeNodeEx(m_root->getName().c_str(), ImGuiTreeNodeFlags_DefaultOpen))
            {
                for(auto child : m_root->m_childs)
                {
                    drawSceneTree(child);
                }
                ImGui::TreePop();
            }
        ImGui::End();

        // --- SAĞ PANEL: PROPERTIES ---
        ImGui::SetNextWindowPos(ImVec2(1300, 350), ImGuiCond_Once); 
        ImGui::SetNextWindowSize(ImVec2(300, 500), ImGuiCond_Once);

        ImGui::Begin("Properties");

        if (m_selectedObject && m_selectedObject != m_root)
        {
            ImGui::Text("Selected: %s", m_selectedObject->getName().c_str());
            ImGui::Separator();

            // 1. TRANSFORMATION
            if(ImGui::CollapsingHeader("Transformation[0]", ImGuiTreeNodeFlags_DefaultOpen))
            {
                ImGui::DragFloat3("Position", &m_selectedObject->transform->position.x, 0.1f);
                ImGui::DragFloat3("Rotation", &m_selectedObject->transform->euler.x, 1.0f);
                ImGui::DragFloat3("Scale", &m_selectedObject->transform->scale.x, 0.1f);
            }

            ImGui::Spacing();

            //  Remove Butonu
            if(ImGui::Button("Remove"))
            {
                if(m_selectedObject->m_parent)
                {
                    m_selectedObject->m_parent->removeChild(m_selectedObject);
                    m_selectedObject = m_root; 
                }
            }

            ImGui::Spacing();
            ImGui::Separator();
            ImGui::Spacing();

            // ---  ATTACH TO CAMERA  ---
            
            // Kontrol: Obje tipi Kamera mı veya İsmi "Camera" mı
            bool isCamera = (m_selectedObject->getType() == SceneObjectType::Camera);
            
            // Eğer getType çalışmıyorsa ismine bakarak kurtaralım:
            if (!isCamera && (m_selectedObject->getName() == "Camera" || m_selectedObject->getName() == "New Camera" || m_selectedObject->getName() == "Main Camera"))
            {
                isCamera = true;
            }

            if(isCamera)
            {
                // Butonu görünür yap
                ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.3f, 0.6f, 0.6f)); // Yeşilimsi renk
                if(ImGui::Button("Attach to Camera", ImVec2(280, 30))) 
                {
                    if(m_secondaryViewPort)
                    {
                        // Zorla Camera pointer'ına dönüştür ve bağla
                        m_secondaryViewPort->attachCamera((Camera*)m_selectedObject);
                    }
                }
                ImGui::PopStyleColor();
            }
            else
            {
                // Sadece kamera değilse bu yazıyı göster
                ImGui::TextDisabled("Select a Camera to attach view.");
            }
            // -------------------------------------------

            ImGui::Separator();
            ImGui::Spacing();

            //  Add Child Model
            static const char* items[] = { "Camera", "Cube", "Cylinder", "Pyramid" };
            static int currentItem = 0;
            
            ImGui::Combo("Models", &currentItem, items, IM_ARRAYSIZE(items));

            if(ImGui::Button("Add Model"))
            {
                SceneObject* newObj = nullptr;

                if(currentItem == 0) // Kamera Ekleme
                {
                    Camera* cam = new Camera(60.0f, 1.0f, 0.1f, 100.0f);
                    cam->m_name = "Camera"; 

                    // --- Kamera parçalarını ekle ---
                    Model* lens = Model::loadModel("Pyramid_UnlitTextured");
                    lens->m_name = "Lens (Pyramid)";
                    lens->transform->position = glm::vec3(0.0f, 0.0f, -1.7f); 
                    lens->transform->scale = glm::vec3(0.5f, 0.5f, 0.6f); 
                    lens->transform->euler.x = -90.0f; 
                    cam->addChild(lens);

                    Model* body = Model::loadModel("Cube_UnlitTextured");
                    body->m_name = "Body (Cube)";
                    body->transform->position = glm::vec3(0.0f, 0.0f, -2.7f); 
                    body->transform->scale = glm::vec3(0.4f, 0.4f, 1.0f); 
                    cam->addChild(body);

                    Model* reelL = Model::loadModel("Cylinder_UnlitTextured");
                    reelL->m_name = "Reel Left";
                    reelL->transform->position = glm::vec3(0.0f, 0.7f, -3.3f); 
                    reelL->transform->scale = glm::vec3(0.7f, 0.6f, 0.7f); 
                    reelL->transform->euler.z = 90.0f; 
                    cam->addChild(reelL);

                    Model* reelR = Model::loadModel("Cylinder_UnlitTextured");
                    reelR->m_name = "Reel Right";
                    reelR->transform->position = glm::vec3(0.0f, 0.7f, -2.2f); 
                    reelR->transform->scale = glm::vec3(0.7f, 0.6f, 0.7f);
                    reelR->transform->euler.z = 90.0f; 
                    cam->addChild(reelR);
                    
                    newObj = cam;
                }
                else if(currentItem == 1) 
                {
                    newObj = Model::loadModel("Cube_UnlitTextured");
                    newObj->m_name = "Cube";
                }
                else if(currentItem == 2)
                {
                    newObj = Model::loadModel("Cylinder_UnlitTextured");
                    newObj->m_name = "Cylinder";
                }
                else if(currentItem == 3)
                {
                    newObj = Model::loadModel("Pyramid_UnlitTextured");
                    newObj->m_name = "Pyramid";
                }

                if(newObj)
                {
                    m_selectedObject->addChild(newObj);
                }
            }
        }
        else
        {
            ImGui::Text("Select an object from the list.");
        }

        ImGui::End();        
    }

    void Scene::drawSceneTree(SceneObject* node)
    {
        ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_DefaultOpen;
        
        if(node == m_selectedObject)
            flags |= ImGuiTreeNodeFlags_Selected;

        if(node->m_childs.empty())
            flags |= ImGuiTreeNodeFlags_Leaf;

        // ID çakışmasını önlemek için pointer adresini ID olarak kullanıyoruz
        bool isOpen = ImGui::TreeNodeEx((void*)node, flags, node->getName().c_str());

        if(ImGui::IsItemClicked())
        {
            m_selectedObject = node;
        }

        if(isOpen)
        {
            for(auto child : node->m_childs)
            {
                drawSceneTree(child);
            }
            ImGui::TreePop();
        }
    }

    void Scene::addModelFromFile(const string &fileName)
    {
        Model* model = Model::loadModel(fileName);
        addSceneObject(model);
    }

    void Scene::addSceneObject(SceneObject *object)
    {
        m_root->addChild(object);
    }

    void Scene::addViewPort(ViewPort * viewPort)
    {
        m_viewPortList.push_back(viewPort);
        // İkinci eklenen viewport'u ikincil olarak kaydet
        if(m_viewPortList.size() > 1)
            m_secondaryViewPort = viewPort;
    }

    void Scene::draw()
    {
        for(auto nextViewPort : m_viewPortList)
        {
            nextViewPort->activateScissor();
            nextViewPort->clearBackground(0.0f, 0.4f, 0.7f, 1.0f);  
            nextViewPort->activate();  
            
            drawScene(nextViewPort);
        }
    }
}