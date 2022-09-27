#pragma once
#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace SnowEngine {
	class SNOW_API Log
	{
	public :
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private :
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


//用宏定义 去除debug代码
//Core log macros
#define SNOW_CORE_ERROR(...) ::SnowEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SNOW_CORE_WARN(...) ::SnowEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SNOW_CORE_INFO(...) ::SnowEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SNOW_CORE_TRACE(...) ::SnowEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SNOW_CORE_FATAL(...) ::SnowEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define SNOW_ERROR(...) ::SnowEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SNOW_WARN(...) ::SnowEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SNOW_INFO(...) ::SnowEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SNOW_TRACE(...) ::SnowEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SNOW_FATAL(...) ::SnowEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)
