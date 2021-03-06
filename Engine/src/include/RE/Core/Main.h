#pragma once

#ifdef RE_PLATFORM_WIN64

#define RE_MAIN(x) \
	int main(int argc, char** argv)	\
	{								\
		RE::Logger::Init();			\
									\
		auto app = new x();			\
		app->Run();					\
		delete app;					\
	}								\
	
#endif
