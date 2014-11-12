// window type used by curses_stream

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef CURSTREAM_WINDOW_HPP
#define CURSTREAM_WINDOW_HPP

extern "C"{
#include <ncurses.h>
}

namespace curstream {
namespace bits {

/* window type */
class window{
public:
  window(
    int
  , int
  , int
  , int
  );

  window(
    window const &
  );

  window &
  operator=(
    window const &
  );

  window(
    window &&
  ) = default;

  window &
  operator=(
    window &&
  ) = default;

  ~window(
  );

  template <typename charT>
  void
  set_border(
    charT
  , charT
  , charT
  , charT
  , charT
  , charT
  , charT
  , charT
  );

  operator WINDOW*() const {return this->win;}

private:
  WINDOW * win;

  int lines, cols, y, x
};

/* window ctor */
window::window(
  int _lines 
, int _cols
, int _y
, int _x
)
  : lines (_lines)
  , cols (_cols)
  , y (_y)
  , x (_x) {
this->win = newwin(_lines, _cols, _y, _x);
}

/* window copy ctor */
window::window(
  window const & _win
){
this->win = newwin(_win.lines, _win.cols, _win.y, _win.x);
}

/* window dtor */
window::~window(
){
delwin(this->win);
}

/* window copy operator */
window &
window::operator(
  window const & _win
){
this->win = newwin();
return *this;
}

/* window set_border */
template <typename charT>
void
window::set_border(
  charT _left
, charT _right
, charT _top
, charT _bottom
, charT _00c
, charT _01c
, charT _10c
, charT _11c
){
wborder(this->win
  , static_cast<chtype>(_left), static_cast<chtype>(_right)
  , static_cast<chtype>(_top), static_cast<chtype>(_bottom)
  , static_cast<chtype>(_00c), static_cast<chtype>(_01c)
  , static_cast<chtype>(_10c), static_cast<chtype>(_11c)
);
}

} /* bits */ } /* curstream */
#endif
