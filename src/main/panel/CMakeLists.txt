# The main xcurses library
add_library("${PanelLib}" SHARED)

# Add library dependencies to xcurses to be linked
# ncurses - The native ncurses implementation
# panel   - panel extension library for ncurses
target_link_libraries("${PanelLib}" ncurses panel)

# Make sure to set the linker language for the library to C++,
# because sometimes CMake has issues figuring out this property
# on its own.
set_target_properties("${PanelLib}" PROPERTIES LINKER_LANGUAGE CXX)

# Source files to be used for xcurses
target_sources("${PanelLib}" PUBLIC panel.hpp)
