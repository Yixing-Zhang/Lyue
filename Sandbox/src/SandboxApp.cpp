#include <Lyue.h>

class ExampleLayer : public Lyue::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//LY_INFO("ExampleLayer::Update");
	}

	void OnEvent(Lyue::Event& e) override
	{
		LY_TRACE("{0}", e);
	}
};

class Sandbox : public Lyue::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Lyue::ImGuiLayer());
	}

	~Sandbox() 
	{

	}
};

Lyue::Application* Lyue::CreateApplication()
{
	return new Sandbox();
}