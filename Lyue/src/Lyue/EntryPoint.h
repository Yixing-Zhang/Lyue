#pragma once

#ifdef LY_PLATFORM_WINDOWS

extern Lyue::Application* Lyue::CreateApplication();

int main(int argc, char** argv)
{
	Lyue::Log::Init();
	LY_CORE_WARN("Initailizing Log!");
	int a = 5;
	LY_INFO("Initailizing Log! Var={0}", a);
	
	auto app = Lyue::CreateApplication();
	app->Run();
	delete app;
}

#endif
