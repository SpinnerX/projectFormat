cmake_minimum_required(VERSION 3.0.0)

set(PROJECT_NAME projectFormat)

project(${PROJECT_NAME} VERSION 0.1.0)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS "-std=c++20")

# Allows us to outputfiles into the project instead of the build directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(libs/formatCpp)

# We are adding more compile options
# Applying linked-time optimizations.
add_compile_options(
  -flto # Combines all multiple objs into one executable
  -fdata-sections #  Enabling data optimization. Data not used by program will not be in executable.
  -fvisibility-inlines-hidden # Hide functions in headers helping reduce size of executable
  -fno-rtti # This flag disables generation of run-tiome type info (which may be used to reduce code size)
)

add_executable(${PROJECT_NAME} main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


target_link_libraries(
    ${PROJECT_NAME}
    FormatCpp::FormatCpp # To link the formatCpp library
    -flto
    -fdata-sections
    -fvisibility-inlines-hidden
)