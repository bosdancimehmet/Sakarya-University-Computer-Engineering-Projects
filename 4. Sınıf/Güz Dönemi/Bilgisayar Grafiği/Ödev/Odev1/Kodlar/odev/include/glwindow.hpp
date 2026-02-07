#ifndef GLWindow_hpp
#define GLWindow_hpp
#define GLFW_INCLUDE_NONE
#include <iostream>
#include<GLFW/glfw3.h>
#include"glad/glad.h"
#include "functiontypes.hpp"
namespace graf
{
    class GLWindow
    {
        public:
            void create(int width,int height);

            GLFWwindow* getWindow();
            void begin();
            void setRenderFunction(RenderFunction function);
            void setGuiFunction(RenderFunction function);
            void setKeyboardFunction(KeyboardFunction function);
            friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
        private:
            void renderImgui();
            void initilizeImgui();
            RenderFunction m_renderFunction;
            RenderFunction m_guiFunction;
            KeyboardFunction m_keyboardFunction;
            GLFWwindow* m_window;
    };
}


#endif