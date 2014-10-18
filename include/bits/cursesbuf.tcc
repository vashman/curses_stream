#ifndef CURSES_STREAM_CURSESBUF_HPP
#define CURSES_STREAM_CURSESBUF_HPP

namespace curses_stream {
template <typename charT, typename traits>
std::size_t basic_ncursesbuf<charT,traits>::active = 0;

template <typename charT, typename traits>
basic_ncursesbuf<charT,traits>::basic_ncursesbuf(){
	if (basic_ncursesbuf<charT,traits>::active < 1){
	windows.push_back(initscr());
	++basic_ncursesbuf<charT,traits>::active;
	this->active_win = 0;
	}
}

template <typename charT, typename traits>
void
basic_ncursesbuf<charT,traits>::set_border(
  charT _left
, charT _right
, charT _top
, charT _bottom
, charT _00c
, charT _01c
, charT _10c
, charT _11c
){
wborder(this->windows[this->active_win]
  , _left, _right, _top, _bottom, _00c, _01c, _10c, _11c);
}

template <typename charT, typename traits>
std::size_t
basic_ncursesbuf<charT,traits>::total_win(
){
return this->windows.size();
}

template <typename charT, typename traits>
void
basic_ncursesbuf<charT,traits>::set_cbreak(
  bool _b
){
	if (_b){
	cbreak();
	} else {
	raw();
	}
}

template <typename charT, typename traits>
void
basic_ncursesbuf<charT,traits>::set_echo(
  bool _b
){
	if (_b){
	echo();
	} else {
	noecho();
	}
}

template <typename charT, typename traits>
void
basic_ncursesbuf<charT,traits>::set_keypad(
  bool _b
){
keypad(this->windows[0], (int)_b);
}

/* cursesstreambuf dtor */
template <typename charT, typename traits>
basic_ncursesbuf<charT,traits>::~basic_ncursesbuf(){
--basic_ncursesbuf<charT,traits>::active;
	if (basic_ncursesbuf<charT,traits>::active == 0){
	endwin();
	}
}

template <typename charT, typename traits>
std::size_t
basic_ncursesbuf<charT,traits>::new_win(
  int _lines
, int _cols
, int _y
, int _x
){
this->windows.push_back(newwin(_lines, _cols, _y, _x));
return this->windows.size()-1;
}

template <typename charT, typename traits>
void
basic_ncursesbuf<charT,traits>::del_win(
  std::size_t _index
){
	if (_index > 0){
	delwin(this->windows[_index]);
	}
}

template <typename charT, typename traits>
std::size_t
basic_ncursesbuf<charT,traits>::set_win(
  std::size_t _index
){
	if (_index < this->windows.size()){
	std::size_t temp = this->active_win;
	this->active_win = _index;
	_index = this->active_win;
	}
return _index;
}

template <typename charT, typename traits>
typename std::basic_streambuf<charT,traits>::int_type
basic_ncursesbuf<charT, traits>::sync(
){
wrefresh(this->windows[this->active_win]);
return traits::to_int_type(0);
}

template <typename charT, typename traits>
typename std::basic_streambuf<charT,traits>::pos_type
basic_ncursesbuf<charT, traits>::seekoff(
  typename std::basic_streambuf<charT, traits>::off_type _off
, std::ios_base::seekdir _way
, std::ios_base::openmode _which
){
int y=0, x=0;
x = getmaxx(this->windows[this->active_win]);
y += _off/x;
x = _off%x;
	if (_way == ios_base::cur){
	x += getcurx(windows[this->active_win]);
	y += getcury(windows[this->active_win]);
	}
	if (_way == ios_base::end){
	x -= getmaxx(windows[this->active_win]);
	y -= getmaxy(windows[this->active_win]);
	}
wmove(windows[this->active_win], y, x);
}

template <typename charT, typename traits>
typename std::basic_streambuf<charT,traits>::pos_type
basic_ncursesbuf<charT, traits>::seekpos(
  typename std::basic_streambuf<charT, traits>::off_type _off
, std::ios_base::openmode _which
){
int y=0, x=0;
x = getmaxx(this->windows[this->active_win]);
y += _off/x;
x = _off%x;
wmove(this->windows[this->active_win], y, x);
}

template <typename charT, typename traits>
typename std::basic_streambuf<charT,traits>::int_type
basic_ncursesbuf<charT, traits>::overflow(
  typename std::basic_streambuf<charT, traits>::int_type _char
){
waddch(this->windows[this->active_win], traits::to_char_type(_char));
return _char;
}

template <typename charT, typename traits>
typename std::basic_streambuf<charT,traits>::int_type
basic_ncursesbuf<charT, traits>::uflow(
){
return this->underflow(); // auto advanced position
}

template <typename charT, typename traits>
std::streamsize
basic_ncursesbuf<charT,traits>::xsputn(
  typename std::basic_streambuf<charT, traits>::char_type * _str
, std::streamsize _size
){
wprintw(this->windows[this->active_win], _str);
return _size;
}

template <typename charT, typename traits>
typename std::basic_streambuf<charT,traits>::int_type
basic_ncursesbuf<charT, traits>::underflow(
){
charT ch = wgetch(this->windows[this->active_win]);
return (ch != ERR) ? traits::to_int_type(ch) : traits::eof();
}

template <typename charT, typename traits>
std::streamsize
basic_ncursesbuf<charT,traits>::xsgetn(
  typename std::basic_streambuf<charT, traits>::char_type * _str
, std::streamsize _size
){
wgetstr(windows[this->active_win], _str);
return _size;
}

} /* curses_stream */
#endif
