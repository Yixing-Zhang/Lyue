#pragma once

#include "Lyue/Core.h"
#include "Lyue/Events/Event.h"

namespace Lyue
{

	class LYUE_API Layer
	{
	public:
		// Constructor & Destructor
		Layer(const std::string& debugName = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& e) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};

}
