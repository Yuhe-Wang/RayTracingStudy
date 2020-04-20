cmake_minimum_required(VERSION 2.8)

project(RayTracingStudy)

set(SRCS main.cpp)
set(HEADERS vec3.h ray.h)


set(FORMAT_TARGET ${SRCS} ${HEADERS})

if(WIN32)
# The non-existing _fake_file.cpp is used to always trigger Prebuild target
add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/_fake_file.cpp
                   COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/tools/clang-format -style=Microsoft -i ${FORMAT_TARGET}
				   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()

add_custom_target(Prebuild ALL
				  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/_fake_file.cpp)


add_executable(RayTracing ${SRCS} ${HEADERS})
add_dependencies(RayTracing Prebuild)
