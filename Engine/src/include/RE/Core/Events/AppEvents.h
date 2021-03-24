#pragma once
#include <RE/REpch.h>
#include <RE/Core/Event.h>

namespace RE::Events
{
	class RE_API WindowEvent : public Event
	{
	public:
		EVENT_CATEGORY(EventCategory::App | EventCategory::AppWindow)
	};

	class RE_API WindowResizedEvent : public WindowEvent
	{
	public:
		EVENT_TYPE(EventType::WindowResized)
		
		WindowResizedEvent(uint32_t width, uint32_t height)
			: m_Width(width), m_Height(height) { }

		uint32_t GetWidth() const { return m_Width; }
		uint32_t GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetName() << ": " << GetWidth() << ", " << GetHeight();
			return ss.str();
		}
		
	private:
		uint32_t m_Width, m_Height;
	};

	class RE_API WindowClosedEvent : public WindowEvent
	{
	public:
		EVENT_TYPE(EventType::WindowClosed)
	};

	class RE_API WindowFocusEvent : public WindowEvent
	{
	public:
		EVENT_TYPE(EventType::WindowFocus)

		WindowFocusEvent(bool focused)
			: m_Focused(focused) { }

		bool IsFocused() const { return m_Focused; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetName() << ": " << IsFocused();
			return ss.str();
		}
		
	private:
		bool m_Focused;
	};
}