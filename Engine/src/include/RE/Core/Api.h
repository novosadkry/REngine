#pragma once

#ifdef RE_PLATFORM_WIN64
	#ifdef RE_BUILD_DLL
		#define RE_API __declspec(dllexport)
	#else
		#define RE_API __declspec(dllimport)
	#endif
#else
	#error Unknown platform
#endif