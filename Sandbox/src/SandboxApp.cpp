#include <Lyue.h>


class Sandbox : public Lyue::Application
{
public:
	Sandbox() 
	{

	}

	~Sandbox() 
	{

	}
};

Lyue::Application* Lyue::CreateApplication()
{
	return new Sandbox();
}