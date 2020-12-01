#include "window.hpp"
#include <cstdlib>

xcu::Window::Window() { this->win_ = newwin(0, 0, 0, 0); }

xcu::Window::Window(const Window &win) { this->win_ = dupwin(win.win_); }

xcu::Window::~Window() { free(this->win_); }
