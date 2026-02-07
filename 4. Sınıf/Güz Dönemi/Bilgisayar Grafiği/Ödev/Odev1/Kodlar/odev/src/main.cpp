#include <iostream>
#include "glwindow.hpp"
#include "shaderprogram.hpp"
#include "scenemanager.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <imgui/imgui.h>

using namespace std;

// Matris Yazdirma Yardımcısı 
void DrawMatrixTable(const char* name, const glm::mat4& mat)
{
    ImGui::Text("%s", name);
    if (ImGui::BeginTable(name, 4, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg))
    {
        for (int row = 0; row < 4; row++)
        {
            ImGui::TableNextRow();
            for (int col = 0; col < 4; col++)
            {
                ImGui::TableSetColumnIndex(col);
                ImGui::Text("%.3f", mat[col][row]);
            }
        }
        ImGui::EndTable();
    }
}

int main(int argc, char** argv)
{
    graf::GLWindow window;
    window.create(1600, 900); 

    // Sahne Yoneticisi
    SceneManager scene;
    scene.loadMeshes();// Meshleri(üçgen noktalarımız) ve texturelari(Kaplama/Doku) yukle
    scene.loadScene("scene.json"); // Kayitli sahneyi yukle

    // Shader Hazirlik
    graf::ShaderProgram program;
    program.create();
    program.attachShader("./shaders/vertex.glsl");
    program.attachShader("./shaders/fragment.glsl");
    program.link();
    
    program.addVariable("uProjectionMatrix");
    program.addVariable("uTransformationMatrix");
    program.addVariable("mySampler");

    // Kamera Ayarları
    float fov = 60.0f;
    float nearPlane = 0.1f;
    float farPlane = 100.0f;
    glm::vec3 defaultCameraPos = glm::vec3(0.0f, 2.0f, -5.0f);
    glm::vec3 cameraPos = defaultCameraPos;

    // GUI'de gostermek icin gecici matrisler
    glm::mat4 viewMatrix(1.0f);
    glm::mat4 projectionMatrix(1.0f);
    
    // RENDER DONGUSU
    window.setRenderFunction([&]()
    {
        glEnable(GL_DEPTH_TEST);
        program.use();
        
        int width, height;
        glfwGetWindowSize(window.getWindow(), &width, &height);
        float aspectRatio = (float)width / (float)height;

        // Projeksiyon & Kamera Left Handed yaptim
        projectionMatrix = glm::perspectiveLH(glm::radians(fov), aspectRatio, nearPlane, farPlane);
        program.setMat4("uProjectionMatrix", projectionMatrix);

        viewMatrix = glm::lookAtLH(cameraPos, glm::vec3(0,0,0), glm::vec3(0,1,0));

        // Tum cizim isini SceneManager'a devret
        scene.render(program, viewMatrix);
    });

    // GUI DONGUSU
    window.setGuiFunction([&]()
    {
        ImGui::Begin("Kontrol Paneli");

        // --- ŞEKİL EKLEME(Küp ya da Piramit) ---
        static const char* items[] = { "Cube", "Pyramid" };
        static int currentItem = 0;
        ImGui::Combo("Shape Type", &currentItem, items, IM_ARRAYSIZE(items));
        
        if(ImGui::Button("Create Shape"))
        {
            scene.addShape(items[currentItem]);
        }

        ImGui::Separator();

        // --- SEÇİLİ ŞEKİL YÖNETİMİ ---
        int currentIdx = scene.getSelectedIndex();
        int shapeCount = scene.getShapes().size();

        if(shapeCount == 0)
        {
            ImGui::Text("Sahnede hic sekil yok.");
        }
        else
        {
            // Index Slider
            if(ImGui::SliderInt("Model Index", &currentIdx, 0, shapeCount - 1))
            {
                scene.selectShape(currentIdx);
            }

            // BUTONLAR
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.1f, 0.6f, 0.6f));
            if(ImGui::Button("SIFIRLA")) scene.resetSelectedShape();
            ImGui::PopStyleColor();

            ImGui::SameLine();

            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.0f, 0.6f, 0.6f));
            if(ImGui::Button("SIL")) scene.deleteSelectedShape();
            ImGui::PopStyleColor();

            // Şekil Özellikleri--> Position, Rotation, Scale
            Shape* s = scene.getSelectedShape();
            if(s)
            {
                ImGui::Text("Type: %s", s->type.c_str());
                ImGui::DragFloat3("Position", &s->position[0], 0.1f);
                ImGui::DragFloat3("Angle", &s->rotation[0], 1.0f, -360.0f, 360.0f);
                ImGui::DragFloat3("Scale", &s->scale[0], 0.1f);
                
                // Seçili olanın matrisini hesapla (Sadece GUI'de göstermek için)
                glm::mat4 model = glm::mat4(1.0f);
                model = glm::translate(model, s->position);
                model = glm::rotate(model, glm::radians(s->rotation.x), glm::vec3(1, 0, 0));
                model = glm::rotate(model, glm::radians(s->rotation.y), glm::vec3(0, 1, 0));
                model = glm::rotate(model, glm::radians(s->rotation.z), glm::vec3(0, 0, 1));
                model = glm::scale(model, s->scale);
                
                ImGui::Separator();
                DrawMatrixTable("World Matrix", model);
            }
        }

        ImGui::Separator();

        // --- KAMERA & PROJEKSİYON ---
        if(ImGui::CollapsingHeader("Camera", ImGuiTreeNodeFlags_DefaultOpen))
        {
            //kamera açısını sıfırlama
            if(ImGui::Button("Kamerayi Sifirla")) cameraPos = defaultCameraPos;
            ImGui::DragFloat3("CamPosition", &cameraPos[0], 0.1f);
            DrawMatrixTable("Camera Matrix", viewMatrix);
        }

        if(ImGui::CollapsingHeader("Projection", ImGuiTreeNodeFlags_DefaultOpen))
        {
            ImGui::SliderFloat("Fov", &fov, 30.0f, 120.0f);
            ImGui::SliderFloat("near", &nearPlane, 0.1f, 10.0f);
            ImGui::SliderFloat("far", &farPlane, 10.0f, 500.0f);
            DrawMatrixTable("Projection Matrix", projectionMatrix);
        }

        ImGui::End();
    });

    window.begin();
    scene.saveScene("scene.json"); // Kapanirken kaydet
    return 0;
}