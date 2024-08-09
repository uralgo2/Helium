project(helium_math)

include_directories(include)

file(GLOB_RECURSE MATH_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE MATH_HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

add_library(helium_math ${MATH_HEADER_FILES} ${MATH_SOURCE_FILES})