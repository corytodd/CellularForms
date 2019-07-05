cmake_minimum_required(VERSION 3.9.2)

project(CellularForms
        LANGUAGES CXX C
        VERSION 0.0.0.0)

include(GNUInstallDirs)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Windows compat -------------------------------------------------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

if(MSVC)
    set(CMAKE_DEBUG_POSTFIX "d")
endif()

# Cross compat --------------------------------------------------------------------
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

# Options -------------------------------------------------------------------------
option(BUILD_SHARED_LIBS "Build libraries as shared as opposed to static" ON)
option(BUILD_TESTING "Create tests using CMake" OFF)

if(BUILD_TESTING)
    enable_testing()
endif()


# Application --------------------------------------------------------------------
add_subdirectory(src)
add_subdirectory(tracer)

if(BUILD_TESTING)
    add_subdirectory(test)
endif()

# Visual Studio ------------------------------------------------------------------
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(VS_STARTUP_PROJECT CellularForms)
set(CMAKE_DEFAULT_STARTUP_PROJECT CellularForms)