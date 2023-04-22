workspace "Sangenpai"
	-- because we include the engine in the solution first, we need to make sure that the selected project is indeed the game
	startproject "Sangenpai"
	-- the engine configuration is automatic and shared between all projects in the workspace
	include "Beryllium/premake5.lua"
	-- our game project
	include "Sangenpai"