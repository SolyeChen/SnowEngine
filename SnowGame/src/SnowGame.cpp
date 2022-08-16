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

int main()
{
	SnowGame* snowgame = new SnowGame();
	snowgame->Run();
	delete snowgame;
}
