#include <memory>
#include "entryPoint.h"
#include <GLFW/glfw3.h>


#define BIND_EVENT(x) std::bind(&app::x , this , std::placeholders::_1)

namespace barn
{
    app::app()
    {
        m_window = std::unique_ptr<window>(window::create());
        m_window->SetEventCallBack(BIND_EVENT(onEvent));
    }
    void app::onEvent(Event& e)
    {
        EventDispatcher dispatcher(e);

        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT(OnWindowClose));

        _CORE_TRACE(e);

    } 


    void app::run()
    {
        while(m_running)
        {
            glClearColor(1 , 0 , 0 , 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_window->onUpdate();
        }
    }    
    

    bool app::OnWindowClose(WindowCloseEvent& e)
    {
        m_running = false;
        return true;
    }
}

