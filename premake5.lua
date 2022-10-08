workspace "SnowEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}--%{cfg.system}--%{cfg.architecture}"

project "SnowEngine"
    location "SnowEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp" 
    }

    includedirs
    {
        "src",
        "%{prj.name}/plugins/spdlog/include", 
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0"

        defines
        {
            "SNOW_PLATFORM_WINDOWS",
            "SNOW_BUILD_DLL",
            "_WINDLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SnowGame")
        }
    filter "configurations:Debug"
        defines "SNOW_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SNOW_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SNOW_DIST"
        optimize "On"
    --filter {"system:windows", "configurations:Release"}
    
project "SnowGame"
    location "SnowGame"
    kind "ConsoleAPP"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp" 
    }

    includedirs
    {
        "SnowEngine/plugins/spdlog/include", 
        "SnowEngine/src"
    }

    links
    {
         "SnowEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0"

        defines
        {
            "SNOW_PLATFORM_WINDOWS",
            --"SNOW_BUILD_DLL", 错误导致无法找到logger
            --"_WINDLL"
        }

    filter "configurations:Debug"
        defines "SNOW_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SNOW_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SNOW_DIST"
        optimize "On"