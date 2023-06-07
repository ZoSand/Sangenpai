#include <Beryllium/Entry.hpp>
#include <Beryllium.hpp>
#include "Application.hpp"


Beryllium::Application* Beryllium::CreateApplication(Beryllium::CmdArgs _args)
{
	Beryllium::ApplicationSpecs specs;
	specs.name = "DemoApp";
	specs.args = _args;
	specs.renderer = new OpenGLRenderer();
	return new Sangenpai::Application(specs);
}