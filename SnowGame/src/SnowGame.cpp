#include <SnowEngine.h>
#include <iostream>
class SnowGame : public SnowEngine::Application
{
public:
	SnowGame()
	{

		SNOW_CORE_INFO("Create SnowGame Made By SnowEngine.");
	}

	~SnowGame()
	{
		SNOW_CORE_INFO("Destroy SnowGame Made By SnowEngine.");
	}

private:

};

SnowEngine::Application* SnowEngine::CreateApplication()
{
	return new SnowGame();
}
