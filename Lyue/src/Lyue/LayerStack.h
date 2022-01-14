#pragma once

#include "Lyue/Core.h"
#include "Layer.h"

namespace Lyue
{

	// Layer Stack to Store Layers in Sequence
	class LYUE_API LayerStack
	{
	public:
		// Constructor & Destructor
		LayerStack() = default;
		~LayerStack();

		// Layer Stack Operations
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		// Layer Stack Iterator Operations
		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
		std::vector<Layer*>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
		std::vector<Layer*>::reverse_iterator rend() { return m_Layers.rend(); }

		std::vector<Layer*>::const_iterator begin() const { return m_Layers.begin(); }
		std::vector<Layer*>::const_iterator end()	const { return m_Layers.end(); }
		std::vector<Layer*>::const_reverse_iterator rbegin() const { return m_Layers.rbegin(); }
		std::vector<Layer*>::const_reverse_iterator rend() const { return m_Layers.rend(); }

	private:
		std::vector<Layer*> m_Layers;
		// The positon to insert a non-overlay layer
		unsigned int m_LayerInsertIndex = 0;
	};

}
