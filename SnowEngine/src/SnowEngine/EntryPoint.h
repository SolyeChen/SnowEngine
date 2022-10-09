#pragma once

#include "Log.h"

#ifdef SNOW_PLATFORM_WINDOWS
extern SnowEngine::Application* SnowEngine::CreateApplication();

//void Say()
//{
//	printf("���\n");
//}
//class A
//{
//public:
//	void Say() { printf("�㲻��\n"); }
//};
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	CMultiDelegate onclick;
//	onclick += newDelegate(Say);
//
//	onclick += newDelegate(&A(), &A::Say);   //ע�����ﲻ�ܴ��� new A(), ��Ϊ���ڴ�й©��
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