// cursesbuf template implementation

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef CURSTREAM_CURSESBUF_TCC
#define CURSTREAM_CURSESBUF_TCC

extern "C"{
#include <ncurses.h>
}

namespace curstream {

/* basic_cursesbuf active */
template <typename charT, typename traits>
std::size_t basic_cursesbuf<charT,traits>::active = 0;

/* basic_cursesbuf ctor */
template <typename charT, typename traits>
basic_cursesbuf<charT,traits>::basic_cursesbuf(
)
  : std::basic_streambuf<charT,traits>() {
	if (basic_cursesbuf<charT,traits>::active == 0){
  initscr();
//  this->init_win = stdscr;
//  this->win = stdscr;
	}
++basic_cursesbuf<charT,traits>::active;
}

/* basic_cursesbuf dtor */
template <typename charT, typename traits>
basic_cursesbuf<charT,traits>::~basic_cursesbuf(
){
--basic_cursesbuf<charT,traits>::active;
	if (basic_cursesbuf<charT,traits>::active == 0){
	endwin();
	}
}

/* basic_cursesbuf set_border */
template <typename charT, typename traits>
void
basic_cursesbuf<charT,traits>::set_border(
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
  , static_cast<chtype>(_left), static_cast<chtype>(_right), static_cast<chtype>(_top), static_cast<chtype>(_bottom)
, static_cast<chtype>(_00c), static_cast<chtype>(_01c), static_cast<chtype>(_10c), static_cast<chtype>(_11c));
}

/* basic_cursesbuf active_win */
template <typename charT, typename traits>
typename basic_cursesbuf<charT,traits>::window_type
basic_cursesbuf<charT,traits>::active_win(
){
return this->win;
}

/* basic_cursesbuf set_cbreak */
template <typename charT, typename traits>
void
basic_cursesbuf<charT,traits>::set_cbreak(
  bool _b
){
	if (_b){
	cbreak();
	} else {
	raw();
	}
}

/* basic_cursesbuf set_echo */
template <typename charT, typename traits>
void
basic_cursesbuf<charT,traits>::set_echo(
  bool _b
){
	if (_b){
	echo();
	} else {
	noecho();
	}
}

/* basic_cursesbuf set_keypad */
template <typename charT, typename traits>
void
basic_cursesbuf<charT,traits>::set_keypad(
  bool _b
){
keypad(this->init_win, static_cast<int>(_b));
}

/* basic_cursesbuf new_win */
template <typename charT, typename traits>
typename basic_cursesbuf<charT,traits>::window_type
basic_cursesbuf<charT,traits>::new_win(
  int _lines
, int _cols
, int _y
, int _x
){
return newwin(_lines, _cols, _y, _x);
}

/* basic_cursesbuf del_win */
template <typename charT, typename traits>
void
basic_cursesbuf<charT,traits>::del_win(
  basic_cursesbuf<charT,traits>::window_type _win
){
delwin(_win);
}

/* basic_cursesbuf set_win
swaps the active window with window parameter and returns
previous window
*/
template <typename charT, typename traits>
typename basic_cursesbuf<charT,traits>::window_type
basic_cursesbuf<charT,traits>::set_win(
  basic_cursesbuf<charT,traits>::window_type _win
){
basic_cursesbuf<charT,traits>::window_type temp = this->win;
this->win =  _win;
_win = temp;
return _win;
}

/* basic_cursesbuf sync */
template <typename charT, typename traits>
typename std::basic_streambuf<charT,traits>::int_type
basic_cursesbuf<charT, traits>::sync(
){
wrefresh(this->win);
return traits::to_int_type(0);
}

/* cursesbuf seekoff */
template <typename charT, typename traits>
typename std::basic_streambuf<charT,traits>::pos_type
basic_cursesbuf<charT, traits>::seekoff(
  typename std::basic_streambuf<charT, traits>::off_type _off
, std::ios_base::seekdir _way
, std::ios_base::openmode _which
){
int y=0, x=0;
x = getmaxx(this->win);
y += _off/x;
x = _off%x;
	if (_way == std::ios_base::cur){
	x += getcurx(this->win);
	y += getcury(this->win);
	}
	if (_way == std::ios_base::end){
	x -= getmaxx(this->win);
	y -= getmaxy(this->win);
	}
wmove(this->win, y, x);
return static_cast<typename std::basic_streambuf<charT,traits>
       ::pos_type>(_off);
}

template <typename charT, typename traits>
typename std::basic_streambuf<charT,traits>::pos_type
basic_cursesbuf<charT, traits>::seekpos(
  typename std::basic_streambuf<charT, traits>::pos_type _off
, std::ios_base::openmode _which
){
int y=0, x=0;
x = getmaxx(this->win);
y += _off/x;
x = _off%x;
wmove(this->win, y, x);
return static_cast<typename std::basic_streambuf<charT,traits>
       ::pos_type>(_off);
}

template <typename charT, typename traits>
typename std::basic_streambuf<charT,traits>::int_type
basic_cursesbuf<charT, traits>::overflow(
  typename std::basic_streambuf<charT, traits>::int_type _char
){
/* waddch loses data because the int_type is converted to the ncurses
   chtype which hold the character infomation, as well as other data
   about the character.
*/
waddch(this->win, static_cast<chtype>(traits::to_char_type(_char)));
return traits::to_int_type(_char);
}

template <typename charT, typename traits>
typename std::basic_streambuf<charT,traits>::int_type
basic_cursesbuf<charT, traits>::uflow(
){
return this->underflow(); // auto advanced position
}

template <typename charT, typename traits>
std::streamsize
basic_cursesbuf<charT,traits>::xsputn(
  const typename std::basic_streambuf<charT, traits>::char_type * _str
, std::streamsize _size
){
wprintw(this->win, _str);
return _size;
}

template <typename charT, typename traits>
typename std::basic_streambuf<charT,traits>::int_type
basic_cursesbuf<charT, traits>::underflow(
){
charT ch = wgetch(this->win);
return (ch != ERR) ? traits::to_int_type(ch) : traits::eof();
}

template <typename charT, typename traits>
std::streamsize
basic_cursesbuf<charT,traits>::xsgetn(
  typename std::basic_streambuf<charT, traits>::char_type * _str
, std::streamsize _size
){
wgetstr(this->win, _str);
return _size;
}

} /* curstream */
#endif
