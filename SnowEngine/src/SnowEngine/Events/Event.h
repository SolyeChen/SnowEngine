#pragma once

#include <string>
#include <functional>

namespace SnowEngine {

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowsMoved,
		AppTick, AppUpdatem, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventnCategoryApplication		= BIT(0),
		EventnCategoryInput				= BIT(1),
		EventnCategoryKeyboard			= BIT(2),
		EventnCategoryMouse				= BIT(3),
		EventnCategoryMousebutton		= BIT(4),
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::#type;}\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
	class Event
	{
	public:
		virtual ~Event() = default;

		bool Handled = false;
		
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); };

		//事件筛选，0说明类型不同
		bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher
	{
	public: 
		EventDispatcher(Event& event) :m_Event(event)
		{

		}

		template<typename T, typename F>
		bool Dispatcher(const F& func)
		{
			if (m_Event.GetEventType == T::GetStaticeType())
			{
				m_Event.Handled |= func(static_cast<T&>(m_Event))
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	//重载cout输出运算符
	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}
