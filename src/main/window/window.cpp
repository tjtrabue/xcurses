#include "window.hpp"
#include <cstdlib>
#include <stdexcept>

// Pull in the custom xcurses namespace.
using namespace xcu;

Window::Window() { win_ = newwin(0, 0, 0, 0); }

Window::Window(const Window &win) {
  if (win.win_) {
    win_ = dupwin(win.win_);
  } else {
    win_ = nullptr;
  }
}

Window::Window(int num_lines, int num_cols, int begin_y, int begin_x) {
  if (num_lines < 0 || num_cols < 0 || begin_y < 0 || begin_x < 0) {
    throw new std::out_of_range(
        "All arguments to Window() must not be negative");
  }
  win_ = newwin(num_lines, num_cols, begin_y, begin_x);
}

Window::~Window() { free(win_); }

Window &Window::operator=(const Window &win) {
  if (win_) {
    free(win_);
  }
  win_ = win.win_;
  return *this;
}
