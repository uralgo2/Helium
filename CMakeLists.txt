cmake_minimum_required(VERSION 3.28)
project(helium)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(engine)
add_subdirectory(math)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)


add_executable(helium main.cpp)
target_link_libraries(helium helium_engine glfw GLEW::GLEW OpenGL::GL glm::glm-header-only  fmt::fmt-header-only)
