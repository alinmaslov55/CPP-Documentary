# CMAKE tool

A `CMakeLists.txt` file is the central script that tells the CMake build system how to compile and link your project. Instead of writing platform-specific Makefiles or Visual Studio projects, you write this one high-level, cross-platform script. CMake then reads it and generates the native build files for your environment.

## The Basic Structure

At its core, a file defines **targets**. A target is something you want to build, like an executable or a library

### For a simple single file project

```c
# 1. Set the minimum CMake version required.
# This also tells CMake what policies (behaviors) to use.
cmake_minimum_required(VERSION 3.15)

# 2. Define your project.
# This sets the project name and can specify languages.
project(MyAwesomeProject LANGUAGES CXX)

# 3. Add an executable target.
# This creates a program named "my_app" from "main.cpp".
add_executable(my_app main.cpp)
```

- `cmake_minimum_requiered(VERSION ...)` - Always the first line. It ensures a user has a new enough version of CMake to build your project
- `project(ProjectName ...)` - Names your project. This is important because CMake creates variables based on this name
- `add_executable(target_name source1.cpp [source2.cpp ...])` - Creates a program
- `add_library(target_name [STATIC | SHARED | MODULE] source1.cpp ...)` - Creates a library.
    - `STATIC` - A static library (`.a` or `.lib`) that gets compiled into its dependent target
    - `SHARED` - A dynamic library (`.so` or `.dll`) that is loaded at runtime

## Modern CMake: Working with Targets

- Modern CMake revolves around setting **properties** on targets. This is more robust than old methods that used global variables. When you link one target to another, its properties can "propagate" automatically.

- Key Commands
    1. `target_include_directories(target_name ...)`
    2. `target_link_libraries(target_name ...)`

- Both Commands use keywords to control how properties propagate
    1. `PRIVATE` - The property (e.g., an include path or library) is only for this target. It does not propagate to targets that link to this one
    2. `INTERFACE` - The property is not for this target, but it will be passed on to any target that links to this one. This is common for header-only libraries
    3. `PUBLIC` - The property is for both this target and any target that links to it. It's the same as `PRIVATE` and `INTERFACE` combined

### Example Executable + Library

```lua
my_project/
├── CMakeLists.txt
├── main.cpp
└── math/
    ├── CMakeLists.txt
    ├── math.cpp
    └── math.h
```

```c
# my_project/CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(MyApp LANGUAGES CXX)

# This command tells CMake to look in the "math" directory
# for another CMakeLists.txt file and run it.
add_subdirectory(math)

# Create the main executable
add_executable(my_app main.cpp)

# Link our "my_app" target against the "my_math_lib" target
# (which will be defined in math/CMakeLists.txt).
# This automatically handles linking the library file and
# also inherits any PUBLIC include directories from my_math_lib.
target_link_libraries(my_app PRIVATE my_math_lib)
```

```c
# my_project/math/CMakeLists.txt
# Create the library target
add_library(my_math_lib STATIC math.cpp math.h)

# We need to tell any target that links to us
# where to find our public header file ("math.h").
target_include_directories(my_math_lib
  PUBLIC
    # CMAKE_CURRENT_SOURCE_DIR is a variable for the current directory
    ${CMAKE_CURRENT_SOURCE_DIR}
)
```

## Variables and Control Flow

- Variables

    - `set()`

    ```c
    # Create a normal variable, visible in this file and subdirectories
    set(MY_VARIABLE "some_value")

    # Use a variable with ${...}
    message(STATUS "My variable's value is: ${MY_VARIABLE}")

    # Add to a list variable
    set(MY_SOURCES main.cpp utils.cpp)
    list(APPEND MY_SOURCES "extra.cpp") # MY_SOURCES is now "main.cpp;utils.cpp;extra.cpp"
    add_executable(my_app ${MY_SOURCES})
    ```

- Cache Variables 
    
    - They are saved in the CMakeCache.txt file in your build directory. They are meant for users to change, like options for your build.

    ```c
    # Create a user-option, a boolean checkbox, defaulting to ON
    set(BUILD_TESTS ON CACHE BOOL "Enable building the unit tests")
    ```

- Control Flow

    ```c
    # Check if the cache variable is ON
    if(BUILD_TESTS)
    message(STATUS "Tests are enabled.")
    add_subdirectory(tests)
    else()
    message(STATUS "Tests are disabled.")
    endif()
    ```


    - Common `if()` conditions include:
        - `if(MY_VARIABLE)`: True if `MY_VARIABLE` is `ON`, `1`, `TRUE`, etc.
        - `if(DEFINED MY_VARIABLE)`: True if the variable has been set at all.
        - `if(EXISTS "path/to/file")`: True if the file or directory exists.
        - `if(MSVC)`: True if the compiler is Microsoft Visual C++. (CMake sets many variables like this).

## Handling External Depenencies

- You rarely build in a vacuum. You need libraries (e.g., zlib, Boost, OpenGL). CMake has two main ways to handle this.

1. `find_package()` - Traditional Way

    - This command finds a library that is already installed on the user's system.

    ```md
    # Find the Zlib package, version 1.2 or newer.
    # REQUIRED means CMake will stop with an error if it's not found.
    find_package(ZLIB 1.2 REQUIRED)

    # If found, it creates an "imported target" named ZLIB::ZLIB.
    # You can just link against it like one of your own targets.
    target_link_libraries(my_app PRIVATE ZLIB::ZLIB)
    ```

    - This works by looking for special files (FindZLIB.cmake or ZLIBConfig.cmake) in system paths

2. `FetchContent` - The Modern Way

    - This command **downloads and builds** the dependency for you as part of your project's configure step. It's fantastic for ensuring all developers are using the exact same version of a library.

    ```md
    # Include the FetchContent module to get the commands
    include(FetchContent)

    # 1. Declare the dependency (where to get it from)
    FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG      release-1.10.0
    )

    # 2. Make it available (downloads and adds its targets)
    FetchContent_MakeAvailable(googletest)

    # Now you can just link against its targets (gtest, gmock)
    # as if you had written them yourself.
    add_executable(my_tests tests.cpp)
    target_link_libraries(my_tests PRIVATE gtest_main)
    ```

## Build Types (Debug vs. Release)

- You should not hardcode build types in your CMakeLists.txt file. This is a choice the user makes when they configure the build.
- For single-configuration generators (Makefiles, Ninja), the user sets the CMAKE_BUILD_TYPE variable on the command line. CMake automatically applies the correct compiler flags.
Bash

```sh
# Configure a Debug build (with symbols, no optimization)
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug

# Build it
cmake --build build

# Re-configure as a Release build (optimized, no symbols)
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release

# Build it again
cmake --build build
```

- The standard build types are:
    - `Debug`: For debugging.
    - `Release`: For optimized, distributable code.
    - `RelWithDebInfo`: A Release build with debug symbols included (good for profiling).
    - `MinSizeRel`: A Release build optimized for the smallest binary size.