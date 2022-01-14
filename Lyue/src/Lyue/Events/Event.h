#pragma once

#include "lypch.h"
#include "Lyue/Core.h"

namespace Lyue
{
	// Events now are in blocking mode, which will be handled immediately.
	// Upgrade to buffer mode in the future.

	// Event Specific Type
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

// Override the Virtual Functions of Event Class for Type
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

	// Event General Category (one event type can be in several categories)
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

// Override the Virtual Function of Event Class for Category
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class LYUE_API Event
	{
	public:
		// Destructor (need to be implemented in child class)
		virtual ~Event() = default;

		// Whether is handled already
		bool Handled = false;

		// const表示不修改对象，=0表示为纯虚函数，无法实例化
		// 同时意味着纯虚函数需要我们去实现它才能调用
		// Getters
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;

		virtual std::string ToString() const { return GetName(); }

		// Whether in certain categories
		bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	// Event Dispatcher that dispactch the event to the corresponding oncall function
	class LYUE_API EventDispatcher
	{
		template<typename T>
		using EventFn = std::function <bool(T&)>;
	public:
		// Constructor
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		// Dispatch the event (call the OnCall functions for the event)
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	// Overload the << for Event
	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}