workspace "RealEngine"
    architecture "x64"

    configurations { "Debug", "Release" }
    platforms { "Engine", "Sandbox" }

	startproject "Sandbox"
	
    outputdir = "%{cfg.system}-%{cfg.architecture}.%{cfg.buildcfg}"

    project "Engine"
        location "Engine"
        kind "SharedLib"

        language "C++"
		
        targetdir ("bin/%{prj.name}/" .. outputdir)
        objdir ("obj/%{prj.name}/" .. outputdir)
		
		pchheader "RE/REpch.h"
		pchsource "Engine/src/impl/RE/REpch.cpp"

        files { 
			"%{prj.name}/src/**.h", 
			"%{prj.name}/src/**.cpp" 
		}
		
		includedirs { "Engine/src/include" }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"

            defines {
                "RE_PLATFORM_WIN64",
                "RE_BUILD_DLL"
            }

        filter "configurations:Debug"
            defines "RE_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "RE_RELEASE"
            optimize "On"

    project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"

        language "C++"

        targetdir ("bin/%{prj.name}/" .. outputdir)
        objdir ("obj/%{prj.name}/" .. outputdir)

        files { 
			"%{prj.name}/src/**.h", 
			"%{prj.name}/src/**.cpp" 
		}

        links { "Engine" }
		includedirs { "Engine/src/include" }
		
		postbuildcommands {
			("{COPY} ../bin/Engine/" .. outputdir .. "/Engine.dll %{cfg.buildtarget.directory}")
		}

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"

            defines { "RE_PLATFORM_WIN64" }

        filter "configurations:Debug"
            defines "RE_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "RE_RELEASE"
            optimize "On"