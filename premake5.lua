workspace "Hydro"
	architecture "x86_64"

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
IncludeDir["GLFW"] = "Dependencies/vendor/GLFW/include"
IncludeDir["GLEW"] = "Dependencies/vendor/GLEW/include"
IncludeDir["OPENAL"] = "Dependencies/vendor/OPENAL/include"
IncludeDir["ASSIMP"] = "Dependencies/vendor/ASSIMP/include"
IncludeDir["LIBVORBIS"] = "Dependencies/vendor/LIBVORBIS/include"
IncludeDir["ImGui"] = "Hydro/src/vendor/imgui"
IncludeDir["glm"] = "Hydro/src/vendor/glm"
IncludeDir["stb_image"] = "Hydro/src/vendor/stbImage"

project "Hydro"
	location "Hydro"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/src/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLEW}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}
	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"Assimp",
		"OpenAl",
		"opengl32.lib"
	}

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/vendor/stb_image/**.h",
		"%{prj.name}/src/vendor/stb_image/**.cpp",
		"%{prj.name}/src/vendor/glm/glm/**.hpp",
		"%{prj.name}/src/vendor/glm/glm/**.inl",
	}

		filter "system:windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		defines "HZ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HZ_DIST"
		runtime "Release"
		optimize "on"
