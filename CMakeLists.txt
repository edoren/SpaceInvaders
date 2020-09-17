project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SPACE_INVADERS_SOURCE_FILES "src/*.cpp")
file(GLOB_RECURSE SPACE_INVADERS_HEADER_FILES "src/*.hpp")
file(GLOB_RECURSE SPACE_INVADERS_INLINE_FILES "src/*.inl")

add_executable(SpaceInvaders ${SPACE_INVADERS_SOURCE_FILES})
target_include_directories(SpaceInvaders PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
conan_target_link_libraries(SpaceInvaders)
