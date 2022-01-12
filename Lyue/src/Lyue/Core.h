#pragma once

#ifdef LY_PLATFORM_WINDOWS
	#ifdef LY_BUILD_DLL
		#define LYUE_API __declspec(dllexport)
	#else
		#define LYUE_API __declspec(dllimport)
	#endif
#else
	#error Lyue only supports Windows!
#endif

#define BIT(x) (1 << x)