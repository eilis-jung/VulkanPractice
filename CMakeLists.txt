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

# Include sub-projects.
add_subdirectory ("VulkanPractice")
add_subdirectory("external")
