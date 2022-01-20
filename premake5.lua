workspace "Lyue"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Lyue/vendor/GLFW/include"
IncludeDir["Glad"] = "Lyue/vendor/Glad/include"
IncludeDir["ImGui"] = "Lyue/vendor/imgui"

group "Dependencies"
	include "Lyue/vendor/GLFW"
	include "Lyue/vendor/Glad"
	include "Lyue/vendor/imgui"

group ""

project "Lyue"
	location "Lyue"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "lypch.h"
	pchsource "Lyue/src/lypch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"LY_PLATFORM_WINDOWS",
			"LY_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "LY_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "LY_RELEASE"
		runtime "Release"
		symbols "On"

	filter "configurations:Dist"
		defines "LY_DIST"
		runtime "Release"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Lyue/vendor/spdlog/include",
		"Lyue/src"
	}

	links
	{
		"Lyue"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"LY_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "LY_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "LY_RELEASE"
		runtime "Release"
		symbols "On"

	filter "configurations:Dist"
		defines "LY_DIST"
		runtime "Release"
		symbols "On"