#pragma once

// On Windows
#ifdef LY_PLATFORM_WINDOWS
	// To Build DLL
	#ifdef LY_BUILD_DLL
		#define LYUE_API __declspec(dllexport)
	// To Use Dll
	#else
		#define LYUE_API __declspec(dllimport)
	#endif
#else
	#error Lyue only supports Windows!
#endif

#ifdef HZ_DEBUG
	#define LY_ENABLE_ASSERTS
#endif

#ifdef LY_ENABLE_ASSERTS
	#define LY_ASSERT(x, ...) { if(!x) { LY_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define LY_CORE_ASSERT(x, ...) { if(!x) { LY_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define LY_ASSERT(x, ...)
	#define LY_CORE_ASSERT(x, ...)
#endif

// Event Categories Bit Operation
#define BIT(x) (1 << x)

// Bind Event Handler Functions
#define LY_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)