#pragma once
#include "Core.h"
namespace SnowEngine {
	class SNOW_API Application
	{
		public:
			Application();
			virtual ~Application();

			void Run();
	};
}