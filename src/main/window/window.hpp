#ifndef _WINDOW_HEADER_
#define _WINDOW_HEADER_

#include <ncurses.h>

/**
 * An ncurses Window representing a two-dimensional array of characters to be
 * printed to the screen.
 */
class Window {
public:
  Window();
  ~Window();

private:
  WINDOW *win_;
};

#endif
