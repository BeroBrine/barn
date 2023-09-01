#pragma once 

#include "Events.h"
#include <sstream>
namespace barn
{
    class KeyEvent : public Event
    {
        inline int GetKeyCode() const {return m_KeyCode;}

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);

        protected:
            KeyEvent(int keycode) : m_KeyCode(keyCode) {} 
        
            int m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent
    {
        public:
            KeyPressedEvent(int keycode , int repeatCount) : KeyEvent(keycode) , m_RepeatCount(repeatCount) {}

            inline GetRepeatCount() const {return m_RepeatCount;}

            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "KeyPressedEvent: " << m_KeyCode << "(" << m_RepeatCount << "repeats )";
                return ss.str();
            }
            EVENT_CLASS_TYPE(KeyPressed)

        private:
            int m_RepeatCount;
    };

    class KeyReleased : public KeyEvent
    {
        public:
            KeyReleased(int keycode) : KeyEvent(keycode) {}
        
            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "KeyReleasedEvent: " << m_KeyCode;
                retunr ss.str(); 
            }

            EVENT_CLASS_TYPE(KeyReleased)
    };
}