workspace "HydroEngine"
	architecture "x86_64"
	startproject "HydroEngine"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Dependencies/GLFW/include"
IncludeDir["GLEW"] = "Dependencies/GLEW/include"
IncludeDir["OPENAL"] = "Dependencies/OPENAL/include"
IncludeDir["ASSIMP"] = "Dependencies/ASSIMP/include"
IncludeDir["LIBVORBIS"] = "Dependencies/LIBVORBIS/include"
IncludeDir["ImGui"] = "HydroEngine/src/vendor/imgui"

project "HydroEngine"
	location "HydroEngine"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	includedirs
	{
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLEW}",
		"%{IncludeDir.ASSIMP}",
		"%{IncludeDir.OPENAL}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.LIBVORBIS}",
		"%{prj.name}/src/vendor/spdlog/include",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}
	links 
	{ 
		"glfw3",
		"glew32s.lib",
		"ImGui",
		"Assimp",
		"OpenAL32",
		"opengl32.lib"
	}

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/vendor/stb_image/**.h",
		"%{prj.name}/src/vendor/stb_image/**.cpp",
		"%{prj.name}/src/vendor/glm/**.hpp",
		"%{prj.name}/src/vendor/glm/**.inl",
	}

		filter "system:windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		defines "HY_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HY_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HY_DIST"
		runtime "Release"
		optimize "on"
