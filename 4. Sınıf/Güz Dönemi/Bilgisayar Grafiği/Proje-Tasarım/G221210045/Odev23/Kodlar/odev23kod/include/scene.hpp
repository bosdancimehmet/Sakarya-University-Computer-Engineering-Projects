#pragma once
#include "sceneobject.hpp"
#include "viewport.hpp"

namespace graf
{
    class Model;
    class Scene
    {
    public:
        Scene();

        void drawScene(ViewPort* viewPort);
        void drawGui();
        void draw(); 
        
        void addModelFromFile(const string& fileName);
        void addSceneObject(SceneObject* object);
        void addViewPort(ViewPort*);
        SceneObject* getRoot() { return m_root; }

    private:
        void drawSceneTree(SceneObject* node);

        ViewPortList m_viewPortList;
        SceneObject* m_root;

        SceneObject* m_selectedObject; 
        ViewPort* m_secondaryViewPort; 

        // KAMERAYI GÖRÜNÜR YAPMAK İÇİN
        Model* m_cameraVisualizer;
    };
}