#pragma once

#include "Core.h"

#include "Lyue/LayerStack.h"
#include "Lyue/Events/Event.h"
#include "Lyue/Events/ApplicationEvent.h"

namespace Lyue
{

	class LYUE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:

	};

	//To be defined in the actual applicaiton
	Application* CreateApplication();

}
