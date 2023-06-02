#include "Application.hpp"
#include "TriangleLayer.hpp"

namespace Sangenpai
{
	Application::Application(Beryllium::ApplicationSpecs _specs)
		: Beryllium::Application(_specs)
	{
		PushLayer(new TriangleLayer());
		//BE_INFO("In-Game Init: %s", typeid(*this).name());
	}

	Application::~Application()
	{
		//BE_INFO("Game Destroy: %s", typeid(*this).name());
	}
}