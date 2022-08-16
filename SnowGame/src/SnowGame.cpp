#include <SnowEngine.h>

class SnowGame : public SnowEngine::Application
{
public:
	SnowGame()
	{

	}

	~SnowGame()
	{

	}

private:

};

SnowEngine::Application* SnowEngine::CreateApplication()
{
	return new SnowGame();
}
