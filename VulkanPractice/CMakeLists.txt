# CMakeList.txt : CMake project for VulkanPractice, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_LIBRARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_LIBRARY_DIR})

foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${PROJECT_BINARY_DIR})
    set( CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${PROJECT_LIBRARY_DIR})
    set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${PROJECT_LIBRARY_DIR})
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )


include_directories("include")

file(GLOB SOURCES
    src/*.cpp
    src/base/*.cpp
)
file(GLOB HEADERS
    include/base/*.h
)
# Add shaders
set(SHADER_DIR_GLSL "shaders/glsl/")
file(GLOB SHADERS_GLSL "${SHADER_DIR_GLSL}/*.vert" "${SHADER_DIR_GLSL}/*.frag" "${SHADER_DIR_GLSL}/*.comp" "${SHADER_DIR_GLSL}/*.geom" "${SHADER_DIR_GLSL}/*.tesc" "${SHADER_DIR_GLSL}/*.tese" "${SHADER_DIR_GLSL}/*.mesh" "${SHADER_DIR_GLSL}/*.task" "${SHADER_DIR_GLSL}/*.rgen" "${SHADER_DIR_GLSL}/*.rchit" "${SHADER_DIR_GLSL}/*.rmiss" "${SHADER_DIR_GLSL}/*.rcall")
set(SHADER_DIR_HLSL "shaders/hlsl/")
file(GLOB SHADERS_HLSL "${SHADER_DIR_HLSL}/*.vert" "${SHADER_DIR_HLSL}/*.frag" "${SHADER_DIR_HLSL}/*.comp" "${SHADER_DIR_HLSL}/*.geom" "${SHADER_DIR_HLSL}/*.tesc" "${SHADER_DIR_HLSL}/*.tese" "${SHADER_DIR_HLSL}/*.mesh" "${SHADER_DIR_HLSL}/*.task" "${SHADER_DIR_HLSL}/*.rgen" "${SHADER_DIR_HLSL}/*.rchit" "${SHADER_DIR_HLSL}/*.rmiss" "${SHADER_DIR_HLSL}/*.rcall")
source_group("Shaders\\GLSL" FILES ${SHADERS_GLSL})
source_group("Shaders\\HLSL" FILES ${SHADERS_HLSL})

add_executable(VulkanPractice ${SOURCES} ${HEADERS} ${SHADERS_GLSL} ${SHADERS_HLSL})
add_dependencies(VulkanPractice glfw)
target_link_libraries(VulkanPractice ${Vulkan_LIBRARY} ${GLFW_LIBRARY})

# Compile shaders

include(${PROJECT_SOURCE_DIR}/cmake/compile_shader.cmake)

compile_shader(
  "${SHADER_FILES}"
  "${TARGET_NAME}"
  "${SHADER_INCLUDE_FOLDER}"
  "${GENERATED_SHADER_FOLDER}"
  "${glslangValidator_executable}")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET VulkanPractice PROPERTY CXX_STANDARD 20)
endif()
