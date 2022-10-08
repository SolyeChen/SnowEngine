#pragma once

#ifdef SNOW_PLATFORM_WINDOWS
	#ifdef SNOW_BUILD_DLL
		#define SNOW_API __declspec(dllexport)
	#else
		#define SNOW_API __declspec(dllimport)
	#endif // SNOW_BUILD_DLL
#else
	#error Snow Only Support Windows Now !
#endif //  SNOW_PLATFORM_WINDOWS

#define BIT(x) (1 << x