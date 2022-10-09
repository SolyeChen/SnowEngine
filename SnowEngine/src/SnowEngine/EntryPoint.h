#pragma once

#include "Log.h"

#ifdef SNOW_PLATFORM_WINDOWS
extern SnowEngine::Application* SnowEngine::CreateApplication();

//void Say()
//{
//	printf("你好\n");
//}
//class A
//{
//public:
//	void Say() { printf("你不好\n"); }
//};
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	CMultiDelegate onclick;
//	onclick += newDelegate(Say);
//
//	onclick += newDelegate(&A(), &A::Say);   //注意这里不能传入 new A(), 因为会内存泄漏。
//
//	onclick();
//}

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