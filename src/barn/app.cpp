#include "app.h"
#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "Log.h"
namespace barn
{
    void app::run()
    {
        WindowResizeEvent e(1920 , 342);
        _CORE_TRACE(e);
        while(true);

    }
    
}

