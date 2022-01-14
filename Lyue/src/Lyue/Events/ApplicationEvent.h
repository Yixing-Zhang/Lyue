#pragma once

#include "Event.h"

namespace Lyue
{

	// Window Resize Event
	class WindowResizeEvent : public Event
	{
	public:
		// Constructor
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height)
		{
		}

		// Window Size Getters
		unsigned int GetWidth() const { return m_Width; }
		unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		// Window Size
		unsigned int m_Width;
		unsigned int m_Height;
	};
	
	// Window Close Event
	class WindowCloseEvent : public Event
	{
	public:
		// Constructor (need to be implemented in the child class)
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
	
	// App Tick Event
	class AppTickEvent : public Event
	{
	public:
		// Constructor (need to be implemented in the child class)
		AppTickEvent() = default;

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
	
	// App Update Event
	class AppUpdateEvent : public Event
	{
	public:
		// Constructor (need to be implemented in the child class)
		AppUpdateEvent() = default;

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
	
	// App Render Event
	class AppRenderEvent : public Event
	{
	public:
		// Constructor (need to be implemented in the child class)
		AppRenderEvent() = default;

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

}