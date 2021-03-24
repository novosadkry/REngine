#pragma once
#include <RE/REpch.h>
#include <RE/Core/Event.h>

namespace RE::Events
{
	using KeyCode = uint32_t;
	
	class RE_API KeyEvent : public Event
	{
	public:
		EVENT_CATEGORY(EventCategory::Input | EventCategory::InputKeyboard)
		
		KeyCode GetKeyCode() const { return m_KeyCode; }

	protected:
		KeyEvent(KeyCode key)
			: m_KeyCode(key) { }
		
		KeyCode m_KeyCode;
	};

	class RE_API KeyPressedEvent : public KeyEvent
	{
	public:
		EVENT_TYPE(EventType::KeyPressed)
		
		KeyPressedEvent(KeyCode key, int repeatCount)
			: KeyEvent(key), m_RepeatCount(repeatCount) { }

		int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetName() << ": " << GetRepeatCount() << "x " << GetKeyCode();
			return ss.str();
		}
	private:
		int m_RepeatCount;
	};

	class RE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		EVENT_TYPE(EventType::KeyReleased)
		
		KeyReleasedEvent(KeyCode key)
			: KeyEvent(key) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetName() << ": " << GetKeyCode();
			return ss.str();
		}
	};
}