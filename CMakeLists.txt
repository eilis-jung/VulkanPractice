# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("VulkanPractice")

# Add include for 3rd-party dependencies
include_directories("external/glfw/include")
include_directories("external/glm")
include_directories("external/vulkan/include")

# Build 3rd-party tools
set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/bin)
set(PROJECT_LIBRARY_DIR ${PROJECT_SOURCE_DIR}/libs)

find_library(Vulkan_LIBRARY NAMES vulkan-1 vulkan PATHS ${CMAKE_SOURCE_DIR}/libs/vulkan)
IF (Vulkan_LIBRARY)
    set(Vulkan_FOUND ON)
    MESSAGE("Using bundled Vulkan library version")
ENDIF()

set(GLFW_LIBRARY ${CMAKE_SOURCE_DIR}/libs/glfw/glfw3.lib)

# Include sub-projects.
add_subdirectory ("VulkanPractice")
add_subdirectory("external")
