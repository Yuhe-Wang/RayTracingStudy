cmake_minimum_required(VERSION 2.8)

project(RayTracingStudy)

set(SRCS main.cpp)
set(HEADERS vec3.h ray.h)

add_executable(RayTracing ${SRCS} ${HEADERS})