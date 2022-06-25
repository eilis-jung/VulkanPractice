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

# Vulkan
#set(WIN_VULKAN_LIB ${CMAKE_SOURCE_DIR}/libs/vulkan)
#include_directories("external/vulkan/include")
set(WIN_VULKAN_LIB "C:/VulkanSDK/1.3.216.0/Lib")
include_directories("C:/VulkanSDK/1.3.216.0/Include/vulkan")
include_directories("C:/VulkanSDK/1.3.216.0/Include/vk_video")


IF(WIN32)
	IF (NOT Vulkan_FOUND)
		find_library(Vulkan_LIBRARY NAMES vulkan-1 vulkan PATHS ${WIN_VULKAN_LIB})
		IF (Vulkan_LIBRARY)
			set(Vulkan_FOUND ON)
			message(${WIN_VULKAN_LIB})
			message(${Vulkan_LIBRARY})
			MESSAGE("Using bundled Vulkan library version")
		ENDIF()
	ENDIF()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_USE_PLATFORM_WIN32_KHR")
ENDIF()

set(GLFW_LIBRARY ${CMAKE_SOURCE_DIR}/libs/glfw/glfw3.lib)

# Include sub-projects.
add_subdirectory ("VulkanPractice")
add_subdirectory("external")
