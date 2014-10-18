// basic_curses_stream template implementation.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef CURSTREAM_CURSES_STREAM_TCC
#define CURSTREAM_CURSES_STREAM_TCC

namespace curstream {
// # ostream
template <typename CharT, typename traits>
basic_ocurses_stream<CharT,traits>::basic_ocurses_stream(
  basic_cursesbuf<CharT,traits> * _buf
)
	: basic_ostream<CharT,traits>(_buf){
}

template <typename CharT, typename traits>
basic_ocurses_stream<CharT,traits>::~basic_ocurses_stream(
){
}

template <typename CharT, typename traits>
basic_cursesbuf<CharT,traits> *
basic_ocurses_stream<CharT,traits>::rdbuf(
) const {
return static_cast<basic_cursesbuf<CharT>*>(
    basic_ostream<CharT,traits>::rdbuf()
  );
}

template <typename CharT, typename traits>
void
basic_ocurses_stream<CharT,traits>::set_win(
  std::size_t _win
){
auto sb = static_cast<basic_cursesbuf<CharT,traits>*>(
    basic_ostream<CharT,traits>::rdbuf()
  );
sb->set_win(_win);
}

template <typename CharT, typename traits>
void
basic_ocurses_stream<CharT,traits>::new_win(
  int _lines
, int _cols
, int _y
, int _x
){
(static_cast<basic_cursesbuf<CharT,traits>*>(basic_ostream<CharT,traits>::rdbuf()))->new_win(_lines, _cols, _y, _x);
}

template <typename CharT, typename traits>
void
basic_ocurses_stream<CharT,traits>::del_win(
  std::size_t _index
){
(static_cast<basic_cursesbuf<CharT,traits>*>(this->rdbuf()))->del_win(_index);
}

template <typename CharT, typename traits>
void
basic_ocurses_stream<CharT,traits>::set_border(
  CharT _left
, CharT _right
, CharT _top
, CharT _bottom
, CharT _00c
, CharT _01c
, CharT _10c
, CharT _11c
){
(static_cast<basic_cursesbuf<CharT,traits>*>(this->rdbuf()))->set_border(_left, _right, _top, _bottom, _00c, _01c, _10c, _11c);
}

// # istream
template <typename CharT, typename traits>
basic_icurses_stream<CharT,traits>::basic_icurses_stream(
  basic_cursesbuf<CharT,traits>* _sb
)
	: basic_istream<CharT,traits>(_sb){
}

template <typename CharT, typename traits>
basic_icurses_stream<CharT,traits>::~basic_icurses_stream(
){
}

template <typename CharT, typename traits>
void
basic_icurses_stream<CharT,traits>::set_win(
  std::size_t _index
){
(static_cast<basic_cursesbuf<CharT,traits>*>(this->rdbuf()))->set_win(_index);
}

template <typename CharT, typename traits>
std::size_t
basic_icurses_stream<CharT,traits>::total_win(
){
return (static_cast<basic_cursesbuf<CharT,traits>*>(this->rdbuf()))->totatl_win();
}

template <typename CharT, typename traits>
void
basic_icurses_stream<CharT,traits>::set_cbreak(
  bool _bool
){
(static_cast<basic_cursesbuf<CharT,traits>*>(this->rdbuf()))->set_cbreak(_bool);
}

template <typename CharT, typename traits>
void
basic_icurses_stream<CharT,traits>::set_echo(
  bool _bool
){
(static_cast<basic_cursesbuf<CharT,traits>*>(this->rdbuf()))->set_echo(_bool);
}

template <typename CharT, typename traits>
void
basic_icurses_stream<CharT,traits>::set_keypad(
  bool _bool
){
(static_cast<basic_cursesbuf<CharT,traits>*>(this->rdbuf()))->set_keypad(_bool);
}

// # iostream
template <typename CharT, typename traits>
basic_iocurses_stream<CharT,traits>::basic_iocurses_stream(
  basic_cursesbuf<CharT,traits>* _sb
)
	: basic_iostream<CharT,traits>(_sb){
}

template <typename CharT, typename traits>
basic_iocurses_stream<CharT,traits>::~basic_iocurses_stream(
){
}

template <typename CharT, typename traits>
basic_cursesbuf<CharT,traits> *
basic_iocurses_stream<CharT,traits>::rdbuf(
) const {
return static_cast<basic_cursesbuf<CharT,traits>*>(basic_iostream<CharT,traits>::rdbuf());
}

template <typename CharT, typename traits>
void
basic_iocurses_stream<CharT,traits>::set_win(
  std::size_t _index
){
(static_cast<basic_cursesbuf<CharT,traits>*>(this->rdbuf()))->set_win(_index);
}

template <typename CharT, typename traits>
std::size_t
basic_iocurses_stream<CharT,traits>::total_win(
){
return (static_cast<basic_cursesbuf<CharT,traits>*>(this->rdbuf()))->totatl_win();
}

template <typename CharT, typename traits>
void
basic_iocurses_stream<CharT,traits>::set_cbreak(
  bool _bool
){
(static_cast<basic_cursesbuf<CharT,traits>*>(this->rdbuf()))->set_cbreak(_bool);
}

template <typename CharT, typename traits>
void
basic_iocurses_stream<CharT,traits>::set_echo(
  bool _bool
){
(static_cast<basic_cursesbuf<CharT,traits>*>(this->rdbuf()))->set_echo(_bool);
}

template <typename CharT, typename traits>
void
basic_iocurses_stream<CharT,traits>::set_keypad(
  bool _bool
){
(static_cast<basic_cursesbuf<CharT,traits>*>(this->rdbuf()))->set_keypad(_bool);
}

template <typename CharT, typename traits>
void
basic_ioncurses_stream<CharT,traits>::new_win(
  int _lines
, int _cols
, int _y
, int _x
){
(static_cast<basic_cursesbuf<CharT,traits>*>(basic_ostream<CharT,traits>::rdbuf()))->new_win(_lines, _cols, _y, _x);
}

template <typename CharT, typename traits>
void
basic_iocurses_stream<CharT,traits>::del_win(
  std::size_t _index
){
(static_cast<basic_cursesbuf<CharT,traits>*>(this->rdbuf()))->del_win(_index);
}

template <typename CharT, typename traits>
void
basic_iocurses_stream<CharT,traits>::set_border(
  CharT _left
, CharT _right
, CharT _top
, CharT _bottom
, CharT _00c
, CharT _01c
, CharT _10c
, CharT _11c
){
(static_cast<basic_cursesbuf<CharT,traits>*>(this->rdbuf()))->set_border(_left, _right, _top, _bottom, _00c, _01c, _10c, _11c);
}

} /* curstream */
#endif
