#include <Beryllium/Entry.hpp>
#include <Beryllium.hpp>
#include "Application.hpp"


Beryllium::Application* Beryllium::CreateApplication(Beryllium::CmdArgs _args)
{
	Beryllium::ApplicationSpecs specs;
	specs.name = "Sangenpai";
	specs.args = _args;
	return new Sangenpai::Application(specs);
}