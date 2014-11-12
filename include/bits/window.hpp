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
    WINDOW *
  );

  window(
    window const &
  ) = default;

  window &
  operator=(
    window const &
  ) = default;

  window(
    window &&
  ) = default;

  window &
  operator=(
    window &&
  ) = default;

  ~window(
  ) = default;

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
};

/* window ctor */
window::window(
  WINDOW * _ptr
){
  if (_ptr != nullptr){
  this->win = _ptr;
  }
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
