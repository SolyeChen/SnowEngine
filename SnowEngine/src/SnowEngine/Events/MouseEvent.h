#pragma once
#include "Event.h"
#include "SnowEngine/Core/MouseCodes.h"

namespace SnowEngine {

	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(const float x, const float y)
			:m_MouseX(x), m_MouseY(y) {}


		~MouseMovedEvent() {};

	private:
		float m_MouseX, m_MouseY;
	};

}