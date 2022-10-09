#pragma once

#include "SnowEngine/Core.h"
#include "SnowEngine/Events/Event.h"
#include "SnowEngine//Core/KeyCode.h"
#include <sstream>

namespace SnowEngine {
	
	class SNOW_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return this->m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategory::EventCategoryKeyboard)

	protected:
		KeyEvent(int keyCode) 
			: m_KeyCode(keyCode) {}

		int m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const KeyCode keyCode, bool isRepeat = false):KeyEvent(keyCode), m_IsRepeat(isRepeat){}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (repeat = " << m_IsRepeat << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		bool m_IsRepeat;
	};

	class KeyReleaseEvent : public KeyEvent
	{
	public:
		KeyReleaseEvent(const KeyCode keyCode) :KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleaseEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(const KeyCode keyCode) :KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}
