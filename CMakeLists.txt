cmake_minimum_required(VERSION 3.28)
project(shooter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

find_package(SDL2 REQUIRED COMPONENTS)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/source)

include_directories(${SOURCE_DIR})
include_directories(${SOURCE_DIR}/headers)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

# Add source to this project's executable. 
add_executable(shooter
  ${SOURCE_DIR}/main.cpp
  ${SOURCE_DIR}/game.cpp
  ${SOURCE_DIR}/sprite.cpp
  ${SOURCE_DIR}/player.cpp
  ${SOURCE_DIR}/bullet.cpp
)

target_link_libraries(shooter PRIVATE SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(shooter PRIVATE SDL2_image::SDL2_image)
target_link_libraries(shooter PRIVATE SDL2_ttf::SDL2_ttf)

file(COPY ../libs/SDL2-2.30.1/lib/x64/SDL2.dll DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ../libs/SDL2_image-2.8.2/lib/x64/SDL2_image.dll DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ../libs/SDL2_ttf-2.22.0/lib/x64/SDL2_ttf.dll DESTINATION ${CMAKE_BINARY_DIR})
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
#file(COPY fonts DESTINATION ${CMAKE_BINARY_DIR})