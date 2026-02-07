#define GLM_ENABLE_EXPERIMENTAL
#include "glwindow.hpp"
#include<glm/glm.hpp>
#include "shaderprogram.hpp"
#include "vertexbuffer.hpp"
#include "vertexarrayobject.hpp"
#include "meshloader.hpp"
#include "texturemanager.hpp"
#include "transform.hpp"
#include "shadermanager.hpp"
#include "model.hpp"
#include "camera.hpp"
#include "viewport.hpp"
#include "scene.hpp"
#include <glm/gtx/transform.hpp>
#include<imgui/imgui.h>

using namespace std;

// ---  Kamera Modeli  ---
void buildFilmCameraModel(graf::Camera* parentCamera)
{
    //Piramit
    graf::Model* lens = graf::Model::loadModel("Pyramid_UnlitTextured");
    lens->m_name = "Lens (Pyramid)";
    // Konum: Gözün hemen arkası 
    lens->transform->position = glm::vec3(0.0f, 0.0f, -1.7f); 
    // Ölçek: Piramiti biraz uzattım
    lens->transform->scale = glm::vec3(0.5f, 0.5f, 0.6f); 
    
    
    // Piramidin ucu  normalde +Y'dir.
    // X ekseninde -90 derece çevirirsek ucu +Z ye bakar.
    // Tabanı -Z ye bakar.
    lens->transform->euler.x = -90.0f; 
    parentCamera->addChild(lens);

    //-------------
    // GÖVDE (Küp)
    //-------------
    graf::Model* body = graf::Model::loadModel("Cube_UnlitTextured");
    body->m_name = "Body (Cube)";
    // Konum: Lensin arkasında 
    body->transform->position = glm::vec3(0.0f, 0.0f, -2.7f); 
    // Ölçek: Kamera gövdesi
    body->transform->scale = glm::vec3(0.4f, 0.4f, 1.0f); 
    parentCamera->addChild(body);

    //------------------
    // Silindirler
    //--------------------
    // Sol Silindir
    graf::Model* reelL = graf::Model::loadModel("Cylinder_UnlitTextured");
    reelL->m_name = "Reel Left";
    // Konum: Gövdenin üstü, önde
    reelL->transform->position = glm::vec3(0.0f, 0.7f, -3.3f); 
    // Ölçek: Yassı tekerlek (X ve Z genişlik, Y kalınlık)
    reelL->transform->scale = glm::vec3(0.7f, 0.6f, 0.7f); 
    // Dönüş: Tekerlek gibi dik durması için Z ekseninde 90 çevir
    reelL->transform->euler.z = 90.0f; 
    parentCamera->addChild(reelL);

    // Sağ Silindir
    graf::Model* reelR = graf::Model::loadModel("Cylinder_UnlitTextured");
    reelR->m_name = "Reel Right";
    // Konum: Gövdenin üstü, arkada
    reelR->transform->position = glm::vec3(0.0f,0.7f, -2.2f); 
    reelR->transform->scale = glm::vec3(0.7f, 0.6f, 0.7f);
    reelR->transform->euler.z = 90.0f; 
    parentCamera->addChild(reelR);
}

int main(int arc,char** argv)
{
    float width = 1600;
    float height = 900;
    
    graf::GLWindow window;
    window.create(width, height);

    graf::Scene scene;

    // --------------------------------------------------------
    // 1. ANA KAMERA (Main Camera) - Sahneyi Gezdiğimiz Kamera
    // --------------------------------------------------------
    graf::Camera* mainCamera = new graf::Camera(60, width/height, 0.1f, 100.0f);
    mainCamera->m_name = "Main Camera";
    mainCamera->transform->position = glm::vec3(0, 10, -25); 
    mainCamera->transform->euler.x = 20.0f; 
    mainCamera->transform->euler.y = 180.0f; 
    scene.getRoot()->addChild(mainCamera);


    // ----------------------
    //  ORTAM (Environment)
    // ----------------------
    graf::SceneObject* ortamRoot = new graf::SceneObject();
    ortamRoot->m_name = "Ortam";
    scene.addSceneObject(ortamRoot); // Root -> Ortam

    // Zemin
    graf::Model* zemin = graf::Model::loadModel("Cube_UnlitTextured");
    zemin->m_name = "Zemin";
    zemin->transform->position = glm::vec3(0, -2, 0);
    zemin->transform->scale = glm::vec3(30.0f, 0.5f, 30.0f); 
    ortamRoot->addChild(zemin);

    // Duvarlar
    graf::Model* onDuvar = graf::Model::loadModel("Cube_UnlitTextured");
    onDuvar->m_name = "OnDuvar";
    onDuvar->transform->position = glm::vec3(0, 5, 15);
    onDuvar->transform->scale = glm::vec3(30.0f, 15.0f, 0.5f);
    ortamRoot->addChild(onDuvar);

    graf::Model* solDuvar = graf::Model::loadModel("Cube_UnlitTextured");
    solDuvar->m_name = "SolDuvar";
    solDuvar->transform->position = glm::vec3(-15, 5, 0);
    solDuvar->transform->scale = glm::vec3(0.5f, 15.0f, 30.0f);
    ortamRoot->addChild(solDuvar);

    graf::Model* sagDuvar = graf::Model::loadModel("Cube_UnlitTextured");
    sagDuvar->m_name = "SagDuvar";
    sagDuvar->transform->position = glm::vec3(15, 5, 0);
    sagDuvar->transform->scale = glm::vec3(0.5f, 15.0f, 30.0f);
    ortamRoot->addChild(sagDuvar);


    // --------------------------------------------
    // Kamera Ortamın İçinde direkt oluşsun
    graf::Camera* filmCam = new graf::Camera(60, 400.0f/300.0f, 0.1f, 100.0f);
    filmCam->m_name = "Camera"; 
    // Odanın ortasında, yerden biraz yüksek
    filmCam->transform->position = glm::vec3(0, 3, 0); 
    // Duvar olmayan yere baksın
    filmCam->transform->euler.y = 180.0f; 
    buildFilmCameraModel(filmCam);
    
    // Hiyerarşi: Root -> Ortam -> Camera
    ortamRoot->addChild(filmCam);


    // -------------------
    // VIEWPORT AYARLARI
    // -------------------
    graf::ViewPort* vpMain = new graf::ViewPort(0, 0, width, height);
    vpMain->attachCamera(mainCamera);
    scene.addViewPort(vpMain);

    graf::ViewPort* vpSec = new graf::ViewPort(width - 400, height - 300, 400, 300);
    vpSec->attachCamera(filmCam);
    scene.addViewPort(vpSec);


    // --------------
    // KONTROLLER
    // --------------
    window.setKeyboardFunction([&](int key,int action){
        float speed = 0.5f; 
        if(key==GLFW_KEY_A) mainCamera->transform->moveLeft(speed);
        if(key==GLFW_KEY_D) mainCamera->transform->moveRight(speed);
        if(key==GLFW_KEY_W) mainCamera->transform->moveForward(speed);
        if(key==GLFW_KEY_S) mainCamera->transform->moveBackward(speed);     
    });

    double oldX, oldY;
    window.mouseCursorPosition(oldX,oldY);
    window.setMouseMoveFunction([&](double x,double y){
        double dx = x - oldX;
        double dy = y - oldY;
        if(window.isMouseRightButtonPressed()) {
            mainCamera->transform->euler.y -= dx * 0.1f;
            mainCamera->transform->euler.x -= dy * 0.1f;
        }
        oldX = x; oldY = y;
    });

    window.setMouseButtonFunction([&](int button, int action, int mods){ });

    window.setGuiFunction([&](){ scene.drawGui(); });
    window.setRenderFunction([&](){ scene.draw(); });

    window.begin();
    exit(EXIT_SUCCESS);
}