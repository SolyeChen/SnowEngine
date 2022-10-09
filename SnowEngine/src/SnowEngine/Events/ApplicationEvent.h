#pragma once

#include "SnowEngine/Events/Event.h"
#include <sstream>
namespace SnowEngine {


	class WindowEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class SNOW_API WindowResizeEvent : public WindowEvent
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}
	
		unsigned GetWidth() const { 
			return this->m_Width; 
		}

		unsigned GetHeight() const { 
			return this->m_Height; 
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowsResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)

	private:
		unsigned int m_Width, m_Height;
	};

	class SNOW_API WindowCloseEvent : public WindowEvent
	{
	public:
		WindowCloseEvent() = default;

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowCloseEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowClose)
	};

	class SNOW_API AppTickEvent : public WindowEvent
	{
	public:
		AppTickEvent() = default;

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "AppTickEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(AppTick)
	};

	class SNOW_API AppRenderEvent : public WindowEvent
	{
	public:
		AppRenderEvent() = default;

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "AppRenderEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(AppRender)
	};

	class SNOW_API AppUpdateEvent : public WindowEvent
	{
	public:
		AppUpdateEvent() = default;

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "AppUpdateEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(AppUpdate)
	};
}
