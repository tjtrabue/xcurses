# Gets rid of some warnings when CMake is run from within Cygwin.
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

# Set compiler commands to Clang/LLVM by default since they are much superior to
# GCC.  Can be overridden with the CC and CXX command line flags.
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

# Standard warning flags for C/C++
set(WarningFlags "-Wall -Werror -pedantic")
# These C/C++ flags are only set for a 'Debug' build
set(DebugFlags "-g")

set(CMAKE_C_FLAGS "${WarningFlags} -std=c99")
set(CMAKE_CXX_FLAGS "${WarningFlags}")

set(CMAKE_C_FLAGS_DEBUG "${DebugFlags}")
set(CMAKE_CXX_FLAGS_DEBUG "${DebugFlags}")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set custom directories
set(ExecOutputDir ${PROJECT_BINARY_DIR}/bin)
set(LibOutputDir ${PROJECT_BINARY_DIR}/lib)

# Set the default directory for generated executable programs
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${ExecOutputDir}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${ExecOutputDir}")

# Set the default directory for generated libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${LibOutputDir}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${LibOutputDir}")

# Generate the compile_commands.json file for Clang
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set library target names
set(XCursesLib "xcurses")
