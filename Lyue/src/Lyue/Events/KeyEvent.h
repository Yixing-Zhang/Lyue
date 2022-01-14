#pragma once

#include "Event.h"

namespace Lyue
{
	
	// General Class for Key Event
	class LYUE_API KeyEvent : public Event
	{
	public:
		// Getter
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)

	protected:
		// Constructor
		KeyEvent(int keycode)
			: m_KeyCode(keycode)
		{
		}

		// Which Key
		int m_KeyCode;
	};


	// Key Pressed Event
	class LYUE_API KeyPressedEvent : public KeyEvent
	{
	public:
		// Constructor
		KeyPressedEvent(int keycode, int repeatcount)
			: KeyEvent(keycode), m_RepeatCount(repeatcount)
		{
		}

		// Getter
		inline int GetRepeateCount() const { return m_RepeatCount; }
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << "(" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		// Count the key repeated times when pressed
		int m_RepeatCount;
	};

	// Key Released Event
	class LYUE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		// Constructor
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode)
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}
