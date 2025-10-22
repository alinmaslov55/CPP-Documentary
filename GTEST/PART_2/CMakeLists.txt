cmake_minimum_required(VERSION 3.14)

project(CPP_Documentary_Part2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_TESTS "Build tests (requires internet to fetch GoogleTest)" ON)

include(FetchContent)

if(BUILD_TESTS)
	# Fetch GoogleTest. This keeps the project self-contained for CI and local dev.
	FetchContent_Declare(
		googletest
		URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
	)

	# For CMake < 3.14 this would need a different approach; we required 3.14 above.
	FetchContent_MakeAvailable(googletest)
endif()

# Library target for the project sources
add_library(turtle STATIC
	src/Turtle.cpp
	src/Painter.cpp
)

target_include_directories(turtle
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if(BUILD_TESTS)
		enable_testing()
		# FetchContent has provided the gtest/gmock targets (gtest, gmock, gtest_main, gmock_main).
		# We link against gmock_main below so the gmock headers are available to the tests.
		include(GoogleTest)

	# Tests executable
	add_executable(turtle_tests
		test/TurtleMock.cpp
	)

		target_link_libraries(turtle_tests
			PRIVATE turtle
			PRIVATE gmock_main
		)

	target_include_directories(turtle_tests
		PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/test
	)

	# Register tests with CTest
	gtest_discover_tests(turtle_tests)
endif()

