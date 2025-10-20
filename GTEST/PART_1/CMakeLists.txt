# 1. Basic Project Setup
# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.14)

# Name your project
project(MyProject LANGUAGES CXX)

# Set the C++ standard (e.g., C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# 2. Include GoogleTest using FetchContent
# This is the modern, preferred way to add GTest to a project.
# It will be downloaded and configured automatically at build time.
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0 # Use a specific, stable tag
)

# Make googletest available to your project
# This adds the necessary targets like GTest::gtest and GTest::gtest_main
FetchContent_MakeAvailable(googletest)


# 3. Enable CTest
# This allows you to run your tests using the 'ctest' command
enable_testing()


# 4. Define Your Application Library
# Build your source code in 'src' as a library.
# This makes it easy for both your tests and any future main executable
# to use the same code.
## Define a header-only (INTERFACE) target for the library sources.
# The original CMakeLists added a header file as a normal library source
# which is misleading for a header-only library. Use INTERFACE so the
# include directories and usage requirements are propagated to consumers
# (like the test executable) without attempting to compile the header.
add_library(my_app_lib INTERFACE)

# Export the include directory as INTERFACE so consumers of my_app_lib
# (for example the test executable) will get the include path.
target_include_directories(my_app_lib
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)


# 5. Define Your Test Executable
# Create an executable for your tests
add_executable(run_tests
  test/QueueTest.cpp

)


# 6. Link Libraries
# Link your test executable against your app library and GTest.
# We use GTest::gtest_main, which includes GTest AND a pre-made main()
# function, so you don't have to write one in your test file.
target_link_libraries(run_tests
  PRIVATE
    my_app_lib
    GTest::gtest_main
)


# 7. Discover Tests
# Automatically add all tests from your 'run_tests' executable
# to CTest.
include(GoogleTest)
gtest_discover_tests(run_tests)