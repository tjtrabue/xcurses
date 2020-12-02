#ifndef _WINDOW_HEADER_
#define _WINDOW_HEADER_

#include <curses.h>

/**
 * Primary xcurses namespace.
 */
namespace xcu {

/**
 * Wrapper class for the ncurses WINDOW struct.
 * Represents a two-dimensional array of characters to be printed to the
 * screen.
 */
class Window {
public:
  /**
   * Default constructor; produces a Window that fills the entire screen.
   */
  Window();

  /**
   * Copy constructor
   */
  Window(const Window &win);

  // Other constructors
  /**
   * Construct a Window at position (0,0) (top left corner of the screen) with
   * the given number of lines and columns.
   */
  Window(int num_lines, int num_cols);
  /**
   * Construct a Window at position (begin_x,begin_y) with the given number of
   * lines and columns.
   */
  Window(int num_lines, int num_cols, int begin_y, int begin_x);

  /**
   * Destructor
   */
  ~Window();

  /**
   * Overloaded assignment operator
   */
  Window &operator=(const Window &win);

private:
  /**
   * Encapsulated ncurses WINDOW structure.
   */
  WINDOW *win_;
};

} // namespace xcu
#endif
