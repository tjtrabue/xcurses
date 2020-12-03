#include "window.hpp"
#include <cstdlib>
#include <curses.h>
#include <stdexcept>

// Pull in the custom xcurses namespace.
using namespace xcu;

// Exception messages
const std::string WIN_ARGS_OUT_OF_RANGE_MSG =
    "All arguments to Window() must not be negative";

Window::Window(int num_lines, int num_cols, int begin_y, int begin_x)
    : children_() {
  if (num_lines < 0 || num_cols < 0 || begin_y < 0 || begin_x < 0) {
    throw new std::out_of_range(WIN_ARGS_OUT_OF_RANGE_MSG);
  }
  win_ = newwin(num_lines, num_cols, begin_y, begin_x);
}

Window::Window() : Window(0, 0, 0, 0) {}

Window::Window(const Window &win) : children_() {
  if (win.win_) {
    win_ = dupwin(win.win_);
  } else {
    win_ = nullptr;
  }
}

Window::Window(int num_lines, int num_cols) {
  if (num_lines < 0 || num_cols < 0) {
    throw new std::out_of_range(WIN_ARGS_OUT_OF_RANGE_MSG);
  }
  win_ = newwin(num_lines, num_cols, 0, 0);
}

Window::~Window() {
  // Recursively destroy child Windows before destroying this window.
  for (Window child : children_) {
    child.~Window();
  }
  if (win_) {
    delwin(win_);
    win_ = nullptr;
  }
}

Window &Window::operator=(const Window &win) {
  if (win_) {
    free(win_);
  }
  win_ = win.win_;
  return *this;
}

Window Window::Duplicate() { return Window(*this); }

void Window::CreateSubWindow(int num_lines, int num_cols, int begin_y,
                             int begin_x) {
  children_.push_back(Window(num_lines, num_cols, begin_y, begin_x));
}

void Window::CreateDerivedWindow(int num_lines, int num_cols, int begin_y,
                                 int begin_x) {
  children_.push_back(Window(num_lines, num_cols, begin_y, begin_x));
}

std::pair<int, int> Window::GetCursorPosition() {
  int y;
  int x;
  getyx(win_, y, x);
  return std::pair<int, int>(y, x);
}

int Window::GetCursorY() { return GetCursorPosition().first; }

int Window::GetCursorX() { return GetCursorPosition().second; }

bool Window::Move(int pos_y, int pos_x) {
  bool moved = false;
  if (mvwin(win_, pos_y, pos_x) != ERR) {
    moved = true;
  }
  return moved;
}
