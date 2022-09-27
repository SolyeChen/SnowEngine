#include <SnowEngine.h>
#include <iostream>
class SnowGame : public SnowEngine::Application
{
public:
	SnowGame()
	{
		std::cout<<"Create SnowGame Made By SnowEngine."<<std::endl;
	}

	~SnowGame()
	{
		std::cout << "Destroy SnowGame Made By SnowEngine."<<std::endl;
	}

private:

};

SnowEngine::Application* SnowEngine::CreateApplication()
{
	return new SnowGame();
}
