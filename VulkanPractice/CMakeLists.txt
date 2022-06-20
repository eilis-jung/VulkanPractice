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

# Add source to this project's executable.
add_executable (VulkanPractice "VulkanPractice.cpp" "VulkanPractice.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET VulkanPractice PROPERTY CXX_STANDARD 20)
endif()


# TODO: Add tests and install targets if needed.
