project(phoenix_render_engine)

file(GLOB_RECURSE PHOENIX_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE PHOENIX_HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

add_library(phoenix_render_engine phoenix_render_engine.cpp ${PHOENIX_HEADER_FILES} ${PHOENIX_SOURCE_FILES})

target_include_directories(phoenix_render_engine PUBLIC include)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

target_link_libraries(phoenix_render_engine glfw GLEW::GLEW OpenGL::GL glm::glm-header-only fmt::fmt-header-only)
