#pragma once

#include "Log.h"
#ifdef SNOW_PLATFORM_WINDOWS
extern SnowEngine::Application* SnowEngine::CreateApplication();

int main(int argc, char** argv)
{
	printf("Snow Engine Entry Point.\n");
	SnowEngine::Log::Init();
	SnowEngine::Log::GetCoreLogger()->warn("Initialize Log!");

	auto app = SnowEngine::CreateApplication();

	printf("Run Snow Engine.\n");
	app->Run();
	delete app;
}

#endif