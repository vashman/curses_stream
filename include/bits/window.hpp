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

} /* bits */ } /* curstream */
#endif
