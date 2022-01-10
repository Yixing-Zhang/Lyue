#pragma once

#ifdef LY_PLATFORM_WINDOWS

extern Lyue::Application* Lyue::CreateApplication();

int main(int argc, char** argv)
{
	printf("Lyue Engine Starting!\n");
	auto app = Lyue::CreateApplication();
	app->Run();
	delete app;
}

#endif
