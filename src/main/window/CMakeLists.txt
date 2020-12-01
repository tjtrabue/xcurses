# Add sources to main library for manipulating ncurses WINDOW structures.
file(GLOB WindowSources *.hpp *.cpp)
target_sources("${MainLib}" PRIVATE "${WindowSources}")
