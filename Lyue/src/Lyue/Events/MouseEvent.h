#pragma once

#include "Event.h"

namespace Lyue
{

	// Mouse Moved Event
	class LYUE_API MouseMovedEvent : public Event
	{
	public:
		// Constructor
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y)
		{
		}

		// Mouse New Pos Getters
		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: (" << m_MouseX << " ," << m_MouseY << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		// Mouse New Position after Moving
		float m_MouseX;
		float m_MouseY;
	};

	// Mouse Scrolled Event
	class LYUE_API MouseScrolledEvent : public Event
	{
	public:
		// Constructor
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset)
		{
		}

		// Scrolled Offsets Getters
		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: (" << m_XOffset << " ," << m_YOffset << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		// Scrolled Offsets
		float m_XOffset;
		float m_YOffset;
	};

	// General Class for Mouse Button Event
	class LYUE_API MouseButtonEvent : public Event
	{
	public:
		// Mosue Button Getter
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryInput)

	protected:
		// Constructor
		MouseButtonEvent(int button)
			: m_Button(button)
		{
		}

		// Which Mouse Button
		int m_Button;
	};

	// Mouse Button Pressed Event
	class LYUE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		// Constructor
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button)
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	// Mouse Button Released Event
	class LYUE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		// Constructor
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button)
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}
