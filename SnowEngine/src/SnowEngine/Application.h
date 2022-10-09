#pragma once

#include "Core.h"
#include "SnowEngine/Events/Event.h"

namespace SnowEngine {
	class SNOW_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();


	};
	//To be defined in Client
	Application* CreateApplication();
}	