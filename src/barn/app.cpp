#include <memory>
#include "entryPoint.h"
#include <GLFW/glfw3.h>
namespace barn
{
    app::app()
    {
        m_window = std::unique_ptr<window>(window::create());
    }
    void app::run()
    {
        while(true)
        {
            glClearColor(1 , 0 , 1 , 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_window->onUpdate();
        }
    }
    
}

