#pragma once
#include "../allHeaders.h"
#include <string>
#define BIT(x) (1 << x)


namespace barn
{
    enum class EventType
    {
        none = 0,
        WindowClose , WindowResize , WindowFocus , WindowLostFocus , WindowMoved,
        KeyPressed , KeyReleased , KeyTyped , 
        MouseButtonPressed , MouseButtonReleased , MouseMoved , MouseScrolled        
    }

    enum EventCategory
    {
        None = 0 , 
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseButton = BIT(4)

    }
#define EVENT_CLASS_TYPE(type) static EventType GetEventType() {return EventType::type}


    class Event
    {
        friend class EventDispatcher;
        public:
            virtual EventType GetEventType() const = 0;
            virtual const char* GetName() const = 0;
            virtual int GetCategoryFlags() const = 0;
            virtual std::string ToString() const {return GetName();} 

            inline bool isInCategory(EventCategory category)
            {
                return GetCategoryFlags() & category;
            }
        protected:
            bool m_handled = false;           
    };

    class EventDispatcher
    {
        template<typename T>
        using eventFn = std::function<bool(T&)>;

        public:
            EventDispatcher(Event& event) : m_Event(event) {}

            template<typename T>
            bool Dispatch(eventFn<T> func)
            {
                if(m_Event.GetEventType() == T::GetStaticType())
                {
                    m_Event.m_handled = func(*(T*)&m_Event);
                    return type;
                }
                return false;
            }

        private:
            Event& m_Event;
    };
}