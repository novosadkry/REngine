workspace "REngine"
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
        pchsource "%{prj.name}/src/impl/RE/REpch.cpp"

        files {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs {
            "%{prj.name}/src/include",
            "%{prj.name}/libs/spdlog/include"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/Sandbox/" .. outputdir .. "\"")
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"

            defines {
                "RE_ENGINE",
                "RE_BUILD_DLL",
                "RE_PLATFORM_WIN64"
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
        includedirs {
            "Engine/src/include",
            "Engine/libs/spdlog/include"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"

            defines {
                "RE_APP",
                "RE_PLATFORM_WIN64"
            }

        filter "configurations:Debug"
            defines "RE_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "RE_RELEASE"
            optimize "On"