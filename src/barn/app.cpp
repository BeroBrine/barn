#include <memory>
#include "entryPoint.h"
#include <iostream>
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
            m_window->onUpdate();
        }
    }
    
}

