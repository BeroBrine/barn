#pragma once

#include "Events.h"

#include <sstream>

namespace barn
{
    class WindowResizeEvent : public Event
    {
        public:
            WindowResizeEvent(unsigned int width , unsigned int height) : m_width(width) , m_height(height) {}

            inline unsigned int GetHeight() const {return m_height; }
            inline unsigned int GetWidth() const {return m_width; }

            std::string ToString() const override 
            {
                std::stringstream ss;
                ss << "WindowResizeEvent: " << m_width << "," << m_height;
                return ss.str();
            }

            EVENT_CLASS_TYPE(WindowResizeEvent)
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
        private:
            unsigned int m_width , m_height;
    };

    class WindowCloseEvent : public Event
    {
        public:
            WindowCloseEvent() {}

            EVENT_CLASS_TYPE(WindowCloseEvent)
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
        
    };


}