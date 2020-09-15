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
IncludeDir["ASSIMP"] = "Dependencies/ASSIMP/include"
IncludeDir["OPENAL"] = "Dependencies/OPENAL/include"
IncludeDir["LIBVORBIS"] = "Dependencies/LIBVORBIS/include"
IncludeDir["GLFW"] = "%{wks.location}/HydroEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/HydroEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/HydroEngine/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/HydroEngine/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/HydroEngine/vendor/stb_image"

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
		"vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.ASSIMP}",
		"%{IncludeDir.OPENAL}",
		"%{IncludeDir.LIBVORBIS}",
		"HydroEngine/vendor/spdlog/include",
	}
	
	libdirs 
	{ 
		"Dependencies/OPENAL/lib",
		"Dependencies/ASSIMP/lib",
		"Dependencies/LIBVORBIS/lib",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}
	links 
	{ 
		"assimp.lib",
		"libvorbisfile_static.lib",
		"libvorbis_static.lib",
		"libogg_static.lib",
		"OpenAL32.lib",
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	group "Dependencies"
	include "HydroEngine/vendor/GLFW"
	include "HydroEngine/vendor/Glad"
	include "HydroEngine/vendor/imgui"
	group ""

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
