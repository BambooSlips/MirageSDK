/**
 * @file BaseEvent.hpp
 * @author BambooSlips
 * @brief BaseEvent class declarations
 * @version 0.1
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

namespace Mirage {
    enum class EventType
    {
        NONE = 0,
        KeyPressed,
        KeyReleased,
        KeyTyped,
        MouseMoved,
        MouseScrolled,
        MouseButtonPressed,
        MouseButtonReleased,
        WindowClose,
        WindowResize,
        WindowFoucs,
        WindowLostFocus,
        WindowMoved,
        AppTick,
        AppUpdate,
        AppRender,
    };

    enum EventCategory
    {
        NONE                     = 0,
        EventCategoryApplication = 1 << 0,
        EventCategoryInput       = 1 << 1,
        EventCategoryKeyboard    = 1 << 2,
        EventCategoryMouse       = 1 << 3,
        EventCategoryMouseButton = 1 << 4,
    };

    // #define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
    //                                virtual EventType GetEventType() const override { return GetStaticType(); }

    // #define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

    class BaseEvent
    {
        public:
            BaseEvent() = default;
            virtual ~BaseEvent() = default;

            /**
             * @brief Get the event type
             * 
             * @return EventType 
             */
            virtual EventType GetEventType() const = 0; 

            /**
             * @brief Get the category flags
             * 
             * @return int 
             */
            virtual int GetCategoryFlags() const = 0;

            /**
             * @brief Set the handling status
             * 
             * @param bHandleStatus 
             */
            inline void SetHandleStatus(bool bHandleStatus) { m_bHandled = bHandleStatus; }

            /**
             * @brief Get the handling status of the event
             * 
             * @return true 
             * @return false 
             */
            inline bool IsHandled() { return m_bHandled; }

            /**
             * @brief 
             * 
             * @param category 
             * @return true 
             * @return false 
             */
            virtual bool IsInCategory(EventCategory category) = 0;
        
        private:
            bool m_bHandled;

    };

    // class EventDispatcher
    // {
    //     public:
    //         EventDispatcher(Event& refEvent);

    //         /**
    //          * @brief dispatch the event
    //          * 
    //          * @tparam T 
    //          * @tparam F 
    //          * @param func 
    //          * @return true 
    //          * @return false 
    //          */
    //         template<typename T, typename F>
    //         bool Dispatch(const F& func)
    //         {
    //             if (m_refEvent.GetEventType() == T::GetStaticType())
    //             {
    //                 m_refEvent.SetHandleStatus(m_refEvent.IsHandled() | 
    //                                         func(static_cast<T&>(m_refEvent)));
    //                 return true;
    //             }
    //             return false;
    //         }

    //     private:
    //         Event& m_refEvent; 
    // };
    // }
}