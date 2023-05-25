#include "Application.hpp"

namespace Sangenpai
{

	Application::Application(Beryllium::ApplicationSpecs _specs)
		: Beryllium::Application(_specs)
	{
		//BE_INFO("In-Game Init: %s", typeid(*this).name());
	}

	Application::~Application()
	{
		//BE_INFO("Game Destroy: %s", typeid(*this).name());
	}

	bool Application::OnEvent(Beryllium::Event& _event)
	{	
		return Beryllium::Application::OnEvent(_event);
	}
}