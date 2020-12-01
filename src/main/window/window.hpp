#ifndef _WINDOW_HEADER_
#define _WINDOW_HEADER_

#include <curses.h>

/**
 * Primary xcurses namespace.
 */
namespace xcu {

/**
 * An ncurses Window representing a two-dimensional array of characters to be
 * printed to the screen.
 */
class Window {
public:
  Window();
  Window(const Window &win);
  ~Window();

  Window &operator=(const Window &win);

private:
  WINDOW *win_;
};

} // namespace xcu
#endif
