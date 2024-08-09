project(helium_engine)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

add_library(helium_engine engine.cpp ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(helium_engine PUBLIC include)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

target_link_libraries(helium_engine glfw GLEW::GLEW OpenGL::GL glm::glm-header-only fmt::fmt-header-only)
