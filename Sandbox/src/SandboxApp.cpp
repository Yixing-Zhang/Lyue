#include <Lyue.h>

#include "imgui/imgui.h"

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
		if (Lyue::Input::IsKeyPressed(LY_KEY_TAB))
		{
			LY_TRACE("Tab is pressed!");
		}
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Lyue::Event& e) override
	{
		//LY_TRACE("{0}", e);
	}
};

class Sandbox : public Lyue::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox() 
	{

	}
};

Lyue::Application* Lyue::CreateApplication()
{
	return new Sandbox();
}