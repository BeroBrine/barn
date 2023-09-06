#pragma once

#include "Events/Events.h"
#include "barnpch.h"

namespace barn
{
    struct windowProp
    {
        std::string title;
        unsigned int width;
        unsigned int height;

        windowProp(const std::string &title = "barn engine" , 
                        unsigned int width = 1280 , 
                        unsigned int height = 720)
                    : title(title) , width(width) , height(height) {}
    };

    class window
    {
        public:
            using EventCallBackFn = std::function<void(Event&)>;

            virtual void onUpdate() const = 0;

            virtual unsigned int GetWidth() const = 0;
            virtual unsigned int GetHeight() const = 0;

            virtual void SetEventCallBack(const EventCallBackFn& callback) = 0;
            virtual void SetVSync(bool enabled) = 0;
            virtual bool IsVSync() const = 0;


            static window* create(const windowProp& props = windowProp());
    };
}

