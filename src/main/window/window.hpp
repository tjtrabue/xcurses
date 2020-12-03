#ifndef _WINDOW_HEADER_
#define _WINDOW_HEADER_

#include <curses.h>
#include <utility>
#include <vector>

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

  // *****************
  // *** Operators ***
  // *****************

  /**
   * Overloaded assignment operator
   */
  Window &operator=(const Window &win);

  // ************************
  // *** Instance methods ***
  // ************************

  /**
   * Produce an exact copy of this Window
   */
  Window Duplicate();

  /**
   * Creates a nested child Window inside this Window.
   * The position of the child Window is relative to the screen,
   * not to the parent Window.
   */
  void CreateSubWindow(int num_lines, int num_cols, int begin_y, int begin_x);

  /**
   * Creates a nested child Window inside this Window.
   * The position of the child Window is relative to the parent.
   */
  void CreateDerivedWindow(int num_lines, int num_cols, int begin_y,
                           int begin_x);

  /**
   * Retrieve the cursor's current position within the Window.
   */
  std::pair<int, int> GetCursorPosition();

  /**
   * Retrieve the cursor's current y-coordinate.
   */
  int GetCursorY();

  /**
   * Retrieve the cursor's current x-coordinate.
   */
  int GetCursorX();

  /**
   * Move the Window to the given (x,y) coordinates.
   */
  bool Move(int pos_y, int pos_x);

private:
  /**
   * Encapsulated ncurses WINDOW structure.
   */
  WINDOW *win_;

  /**
   * List of this Window's child Windows
   */
  std::vector<Window> children_;
};

} // namespace xcu
#endif
