#pragma once
#include <RE/REpch.h>

namespace RE::Events
{
	enum class EventType
	{
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
		WindowResized, WindowClosed, WindowFocus, WindowMoved
	};

	enum class EventCategory
	{
		App				= 1,
		AppWindow		= 2,
		Input			= 4,
		InputKeyboard	= 8,
		InputMouse		= 16
	};

	template<typename T>
	using EnumType = typename std::underlying_type<T>::type;

	template<typename T = EnumType<EventCategory>>
	auto operator&(EventCategory lhs, EventCategory rhs)
	{
		return static_cast<T>(
			static_cast<EnumType<EventCategory>>(lhs) &
			static_cast<EnumType<EventCategory>>(rhs)
		);
	}

	template<typename T = EnumType<EventCategory>>
	auto operator|(EventCategory lhs, EventCategory rhs)
	{
		return static_cast<T>(
			static_cast<EnumType<EventCategory>>(lhs) |
			static_cast<EnumType<EventCategory>>(rhs)
		);
	}

	#define EVENT_TYPE(type)													\
		static EventType GetStaticType() { return type; }						\
		virtual EventType GetType() const override { return GetStaticType(); }	\
		virtual const char* GetName() const override { return #type; }			\

	#define EVENT_CATEGORY(category)																	\
		static EventCategory GetStaticCategoryFlags() { return static_cast<EventCategory>(category); }	\
		virtual EventCategory GetCategoryFlags() const override { return GetStaticCategoryFlags(); }	\
	
	class RE_API Event
	{
	public:
		bool Handled = false;
		
		virtual EventType GetType() const = 0;
		virtual EventCategory GetCategoryFlags() const = 0;

		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }

		bool HasCategory(EventCategory category) const
		{
			return GetCategoryFlags() & category;
		}

		friend std::ostream& operator<<(std::ostream& os, const Event& e)
		{
			return os << e.ToString();
		}
	};

	class RE_API EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_Event(event) { }

		template<typename T, typename Func>
		bool Dispatch(const Func& func)
		{
			if (T* event = dynamic_cast<T*>(&m_Event))
			{
				event->Handled |= func(*event);
				return true;
			}

			return false;
		}
		
	private:
		Event& m_Event;
	};
}
