project "Sangenpai"
	location ""
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	links {
		"Beryllium"
	}
	files {
		"**.cd",
		"include/**.hpp",
		"include/**.inl",
		"src/**.cpp"
	}
	includedirs {
		"%{wks.location}/Beryllium/core/include",
		"%{wks.location}/Beryllium/vendor/glm",
		"include"
	}