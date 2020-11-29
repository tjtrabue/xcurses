# The main xcurses library
add_library("${MainLib}" SHARED)

# Add library dependencies to xcurses to be linked
# ncurses - The native ncurses implementation
# panel   - panel extension library for ncurses
target_link_libraries("${MainLib}" ncurses panel)

# Make sure to set the linker language for the library to C++,
# because sometimes CMake has issues figuring out this property
# on its own.
set_target_properties("${MainLib}" PROPERTIES LINKER_LANGUAGE CXX)

# Source files to be used for xcurses
target_sources("${MainLib}" PUBLIC xcurses.hpp)
