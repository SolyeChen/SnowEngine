#pragma once

#ifdef SNOW_PLATFORM_WINDOWS
extern SnowEngine::Application* SnowEngine::CreateApplication();

int main(int argc, char** argv)
{
	printf("Snow Engine Entry Point.");
	auto app = SnowEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif