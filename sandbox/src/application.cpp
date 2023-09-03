#include "allHeaders.h"
namespace barn 
{
    class Sandbox : public app
    {
        public:
            Sandbox()
            {

            }

            ~Sandbox()
            {

            }
    };
    
    
    app* CreateApplication()
    {
        return new Sandbox;
    }
    
}