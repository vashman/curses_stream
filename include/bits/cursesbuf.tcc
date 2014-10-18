#ifndef CURSTREAM_CURSESBUF_HPP
#define CURSTREAM_CURSESBUF_HPP

namespace curstream {

template <typename CharT, typename traits>
std::size_t basic_cursesbuf<CharT,traits>::active = 0;

template <typename CharT, typename traits>
basic_cursesbuf<CharT,traits>::basic_cursesbuf(){
	if (basic_cursesbuf<CharT,traits>::active < 1){
	windows.push_back(initscr());
	++basic_cursesbuf<CharT,traits>::active;
	this->active_win = 0;
	}
}

template <typename CharT, typename traits>
void
basic_cursesbuf<CharT,traits>::set_border(
  CharT _left
, CharT _right
, CharT _top
, CharT _bottom
, CharT _00c
, CharT _01c
, CharT _10c
, CharT _11c
){
wborder(this->windows[this->active_win]
  , _left, _right, _top, _bottom, _00c, _01c, _10c, _11c);
}

template <typename CharT, typename traits>
std::size_t
basic_cursesbuf<CharT,traits>::total_win(
){
return this->windows.size();
}

template <typename CharT, typename traits>
void
basic_cursesbuf<CharT,traits>::set_cbreak(
  bool _b
){
	if (_b){
	cbreak();
	} else {
	raw();
	}
}

template <typename CharT, typename traits>
void
basic_cursesbuf<CharT,traits>::set_echo(
  bool _b
){
	if (_b){
	echo();
	} else {
	noecho();
	}
}

template <typename CharT, typename traits>
void
basic_cursesbuf<CharT,traits>::set_keypad(
  bool _b
){
keypad(this->windows[0], static_cast<int>(_b));
}

/* cursesstreambuf dtor */
template <typename CharT, typename traits>
basic_cursesbuf<CharT,traits>::~basic_cursesbuf(
){
--basic_cursesbuf<CharT,traits>::active;
	if (basic_cursesbuf<CharT,traits>::active == 0){
	endwin();
	}
}

template <typename CharT, typename traits>
std::size_t
basic_cursesbuf<CharT,traits>::new_win(
  int _lines
, int _cols
, int _y
, int _x
){
this->windows.push_back(newwin(_lines, _cols, _y, _x));
return this->windows.size()-1;
}

template <typename CharT, typename traits>
void
basic_cursesbuf<CharT,traits>::del_win(
  std::size_t _index
){
	if (_index > 0){
	delwin(this->windows[_index]);
	}
}

template <typename CharT, typename traits>
std::size_t
basic_cursesbuf<CharT,traits>::set_win(
  std::size_t _index
){
	if (_index < this->windows.size()){
	std::size_t temp = this->active_win;
	this->active_win = _index;
	_index = this->active_win;
	}
return _index;
}

template <typename CharT, typename traits>
typename std::basic_streambuf<CharT,traits>::int_type
basic_cursesbuf<CharT, traits>::sync(
){
wrefresh(this->windows[this->active_win]);
return traits::to_int_type(0);
}

template <typename CharT, typename traits>
typename std::basic_streambuf<CharT,traits>::pos_type
basic_cursesbuf<CharT, traits>::seekoff(
  typename std::basic_streambuf<CharT, traits>::off_type _off
, std::ios_base::seekdir _way
, std::ios_base::openmode _which
){
int y=0, x=0;
x = getmaxx(this->windows[this->active_win]);
y += _off/x;
x = _off%x;
	if (_way == std::ios_base::cur){
	x += getcurx(windows[this->active_win]);
	y += getcury(windows[this->active_win]);
	}
	if (_way == std::ios_base::end){
	x -= getmaxx(windows[this->active_win]);
	y -= getmaxy(windows[this->active_win]);
	}
wmove(windows[this->active_win], y, x);
}

template <typename CharT, typename traits>
typename std::basic_streambuf<CharT,traits>::pos_type
basic_cursesbuf<CharT, traits>::seekpos(
  typename std::basic_streambuf<CharT, traits>::off_type _off
, std::ios_base::openmode _which
){
int y=0, x=0;
x = getmaxx(this->windows[this->active_win]);
y += _off/x;
x = _off%x;
wmove(this->windows[this->active_win], y, x);
}

template <typename CharT, typename traits>
typename std::basic_streambuf<CharT,traits>::int_type
basic_cursesbuf<CharT, traits>::overflow(
  typename std::basic_streambuf<CharT, traits>::int_type _char
){
waddch(this->windows[this->active_win], traits::to_char_type(_char));
return _char;
}

template <typename CharT, typename traits>
typename std::basic_streambuf<CharT,traits>::int_type
basic_cursesbuf<CharT, traits>::uflow(
){
return this->underflow(); // auto advanced position
}

template <typename CharT, typename traits>
std::streamsize
basic_cursesbuf<CharT,traits>::xsputn(
  typename std::basic_streambuf<CharT, traits>::char_type * _str
, std::streamsize _size
){
wprintw(this->windows[this->active_win], _str);
return _size;
}

template <typename CharT, typename traits>
typename std::basic_streambuf<CharT,traits>::int_type
basic_cursesbuf<CharT, traits>::underflow(
){
CharT ch = wgetch(this->windows[this->active_win]);
return (ch != ERR) ? traits::to_int_type(ch) : traits::eof();
}

template <typename CharT, typename traits>
std::streamsize
basic_cursesbuf<CharT,traits>::xsgetn(
  typename std::basic_streambuf<CharT, traits>::char_type * _str
, std::streamsize _size
){
wgetstr(windows[this->active_win], _str);
return _size;
}

} /* curstream */
#endif
