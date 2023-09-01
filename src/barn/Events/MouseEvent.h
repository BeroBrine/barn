#pragma once

#include "Events.h"
#include <sstream>

namespace barn
{
    class MouseMovedEvent : public Event
    {
        public:
            MouseMovedEvent(float x , float y) : m_mousePosX(x) , m_mousePosY(y) {}

            inline float GetX() const {return m_mousePosX; }
            inline float GetY() const {return m_mousePosY; }

            std::string ToString() const override 
            {
                std::stringstream ss;
                ss << "Mouse Moved Event in x " << m_mousePosX << " and in Y " << m_mousePosY;
                return ss.str(); 
            }

            EVENT_CLASS_TYPE(MouseMoved)
            EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

        private:
            float m_mousePosX , m_mousePosY ;
    };

    class MouseScrolledEvent : public Event
    {
        public:
            MouseScrolledEvent(float xOffset , float yOffset) : m_xOffset(xOffset) , m_yOffset(yOffset) {}

            inline float GetxOffset() const {return m_xOffset;}
            inline float GetyOffset() const {return m_yOffset;}

            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "MouseScrolledEvent : " << m_xOffset << " , " << m_yOffset;
                return ss.str();
            }

            EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
            EVENT_CLASS_TYPE(MouseScrolled)
        private:
            float m_xOffset , m_yOffset;

    };

    class MouseButtonEvent : public Event
    {
        public:
            inline int GetMouseButton() {return m_button;}

            EVENT_CLASS_CATEGORY(EventCategoryMouseButton)
        protected:
            MouseButtonEvent(int button) : m_button(button) {}
            int m_button;

    };

    class MouseButtonPressed : public MouseButtonEvent
    {
        public:
            MouseButtonPressed(int pressedButton) : MouseButtonEvent(pressedButton) {}

            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "MouseButtonPressedEvent " << m_button;
                return ss.str();
            }
        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class MouseButtonReleased : public MouseButtonEvent
    {
        public:
            MouseButtonReleased(int button) : MouseButtonEvent(button) {}

            std::string ToString() const override 
            {
                std::stringstream ss;
                ss << "MouseButtonReleased " << m_button;
                return ss.str();
            }
            EVENT_CLASS_TYPE(MouseButtonReleased)
        
    };
}