#pragma once

#ifdef RE_PLATFORM_WIN64

#define RE_MAIN(x) \
	int main(int argc, char** argv)	\
	{								\
		auto app = new x();			\
		app->Run();					\
		delete app;					\
	}								\
	
#endif
