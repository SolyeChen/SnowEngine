#include "Application.h"

#include "SnowEngine/Events/ApplicationEvent.h"
#include "SnowEngine/Log.h"

namespace SnowEngine {
	Application::Application()
	{

	}

	Application::~Application()
	{

	}
	void Application :: Run()
	{
		WindowResizeEvent e(1920, 1080);
		SNOW_TRACE(e);
		while (true);
	}
}