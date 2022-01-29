#pragma once

#include "Core.h"

#include "Lyue/Window.h"
#include "Lyue/LayerStack.h"

#include "Lyue/Events/Event.h"
#include "Lyue/Events/ApplicationEvent.h"

#include "Lyue/ImGui/ImGuiLayer.h"

namespace Lyue
{

	class LYUE_API Application
	{
	public:
		// Constructor & Destructor
		Application();
		virtual ~Application();

		// What Application does when Running
		void Run();

		// Function that Executes when Event e Happens
		void OnEvent(Event& e);

		// Appliaction Layers Operates
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		// Getters
		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		// Functions
		// Function that Executes when Window Closed
		bool OnWindowClose(WindowCloseEvent& e);

		// Attributes
		// Instance
		static Application* s_Instance;
		// The Application Window
		std::unique_ptr<Window> m_Window;
		// The ImGui Layer
		ImGuiLayer* m_ImGuiLayer;
		// Apllication Whether Still Running
		bool m_Running = true;
		// Application Layer Stack
		LayerStack m_LayerStack;
	};

	//To be defined in the actual applicaiton
	Application* CreateApplication();

}
