#pragma once
#include <RE/REpch.h>
#include <RE/Core/Event.h>

namespace RE::Events
{
	using KeyCode = uint32_t;
	
	class RE_API MouseEvent : public Event
	{
	public:
		EVENT_CATEGORY(EventCategory::Input | EventCategory::InputMouse)
	};

	class RE_API MouseMovedEvent : public MouseEvent
	{
	public:
		EVENT_TYPE(EventType::MouseMoved)

		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) { }

		float GetX() const { return m_MouseX; }
		float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetName() << ": " << GetX() << ", " << GetY();
			return ss.str();
		}

	private:
		float m_MouseX, m_MouseY;
	};

	class RE_API MouseScrolledEvent : public MouseEvent
	{
	public:
		EVENT_TYPE(EventType::MouseScrolled)

		MouseScrolledEvent(float offsetX, float offsetY)
			: m_OffsetX(offsetX), m_OffsetY(offsetY) { }

		float GetOffsetX() const { return m_OffsetX; }
		float GetOffsetY() const { return m_OffsetY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetName() << ": " << GetOffsetX() << ", " << GetOffsetY();
			return ss.str();
		}

	private:
		float m_OffsetX, m_OffsetY;
	};

	class RE_API MouseButtonEvent : public MouseEvent
	{
	public:
		KeyCode GetKeyCode() const { return m_KeyCode; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetName() << ": " << GetKeyCode();
			return ss.str();
		}
		
	protected:
		MouseButtonEvent(KeyCode key)
			: m_KeyCode(key) { }

		KeyCode m_KeyCode;
	};

	class RE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		EVENT_TYPE(EventType::MouseButtonPressed)

		MouseButtonPressedEvent(KeyCode key)
			: MouseButtonEvent(key) { }
	};

	class RE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		EVENT_TYPE(EventType::MouseButtonReleased)

		MouseButtonReleasedEvent(KeyCode key)
			: MouseButtonEvent(key) { }
	};
}