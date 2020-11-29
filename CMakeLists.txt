# Oldest compatible version of CMake for this project
cmake_minimum_required(VERSION 3.17.3 FATAL_ERROR)

# Set the project name and version
# The semantic version fields can be later referenced as
#   <project name>_VERSION_MAJOR
#   <project name>_VERSION_MINOR
#   <project name>_VERSION_PATCH
# NOTE: These fields will be empty if the version sub-number is a 0.
#       Thus, a version number of 1.0.1 will have no defined value
#       for <project name>_VERSION_MINOR, but the other version variables
#       will be defined since they are non-zero.
project(xcurses VERSION 0.1.0 LANGUAGES C CXX)

# Allows the add_test function for adding unit test programs.
# NOTE: You should build your test targets AFTER all other targets, since they
#       depend on up-to-date runnable code.
enable_testing()

# The configuration file
configure_file(xcurses_config.hpp.in xcurses_config.hpp)

# Pull in global variables from external file.
include("cmake/global_vars.cmake")

# Run the CMake lists in the source code directory.
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/src")
