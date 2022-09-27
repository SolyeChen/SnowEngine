#pragma once

#include "Log.h"
#ifdef SNOW_PLATFORM_WINDOWS
extern SnowEngine::Application* SnowEngine::CreateApplication();

int main(int argc, char** argv)
{
	SnowEngine::Log::Init();
	SNOW_CORE_INFO("Initialize Log!");

	auto app = SnowEngine::CreateApplication();

	SNOW_CORE_INFO("Run Snow Engine.");
	app->Run();
	delete app;
}

#endif