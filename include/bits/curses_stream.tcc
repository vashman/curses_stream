// basic_curses_stream template implementation.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef CURSTREAM_CURSES_STREAM_TCC
#define CURSTREAM_CURSES_STREAM_TCC

namespace curstream {
/* basic_ocurses_stream ctor */
template <typename charT, typename traits>
basic_ocurses_stream<charT,traits>::basic_ocurses_stream(
  basic_cursesbuf<charT,traits> * _buf
)
	: std::basic_ostream<charT,traits>(_buf){
}

/* basic_ocurses_stream dtor */
template <typename charT, typename traits>
basic_ocurses_stream<charT,traits>::~basic_ocurses_stream(
){
}

/* ocurses_stream rdbuf*/
template <typename charT, typename traits>
basic_cursesbuf<charT,traits> *
basic_ocurses_stream<charT,traits>::rdbuf(
) const {
return static_cast<basic_cursesbuf<charT>*>(
    std::basic_ostream<charT,traits>::rdbuf()
  );
}

/* ocurses_stream set_win */
template <typename charT, typename traits>
typename basic_ocurses_stream<charT,traits>::window_type
basic_ocurses_stream<charT,traits>::set_win(
  basic_ocurses_stream<charT,traits>::window_type _win
){
auto sb = static_cast<basic_cursesbuf<charT,traits>*>(
    std::basic_ostream<charT,traits>::rdbuf()
  );
return sb->set_win(_win);
}

/* ocurses_stream new_win */
template <typename charT, typename traits>
typename basic_ocurses_stream<charT,traits>::window_type
basic_ocurses_stream<charT,traits>::new_win(
  int _lines
, int _cols
, int _y
, int _x
){
return (static_cast<basic_cursesbuf<charT,traits>*>(
          std::basic_ostream<charT,traits>::rdbuf())
       )->new_win(_lines, _cols, _y, _x);
}

/* ocurses_stream del_win */
template <typename charT, typename traits>
void
basic_ocurses_stream<charT,traits>::del_win(
  typename basic_ocurses_stream<charT,traits>::window_type _win
){
(static_cast<basic_cursesbuf<charT,traits>*>(this->rdbuf())
   )->del_win(_win);
}

/* ocurses_stream set_border */
template <typename charT, typename traits>
void
basic_ocurses_stream<charT,traits>::set_border(
  charT _left
, charT _right
, charT _top
, charT _bottom
, charT _00c
, charT _01c
, charT _10c
, charT _11c
){
(static_cast<basic_cursesbuf<charT,traits>*>(this->rdbuf()))->set_border(_left, _right, _top, _bottom, _00c, _01c, _10c, _11c);
}

/* basic_icurses_stream ctor */
template <typename charT, typename traits>
basic_icurses_stream<charT,traits>::basic_icurses_stream(
  basic_cursesbuf<charT,traits> * _sb
)
	: std::basic_istream<charT,traits>(_sb){
}

/* basic_icurses_stream dtor */
template <typename charT, typename traits>
basic_icurses_stream<charT,traits>::~basic_icurses_stream(
){
}

/* basic_icurses_stream set_win */
template <typename charT, typename traits>
typename basic_icurses_stream<charT,traits>::window_type
basic_icurses_stream<charT,traits>::set_win(
  window_type _index
){
return (static_cast<basic_cursesbuf<charT,traits> *>(this->rdbuf()))
       ->set_win(_index);
}

/* icurses_stream active_win */
template <typename charT, typename traits>
typename basic_icurses_stream<charT,traits>::window_type
basic_icurses_stream<charT,traits>::active_win(
){
return (static_cast<basic_cursesbuf<charT,traits>*>(this->rdbuf()))
       ->active_win();
}

/* icurses_stream set_cbreak */
template <typename charT, typename traits>
void
basic_icurses_stream<charT,traits>::set_cbreak(
  bool _bool
){
(static_cast<basic_cursesbuf<charT,traits>*>(this->rdbuf()))
->set_cbreak(_bool);
}

/* icurses_stream set_echo */
template <typename charT, typename traits>
void
basic_icurses_stream<charT,traits>::set_echo(
  bool _bool
){
(static_cast<basic_cursesbuf<charT,traits>*>(this->rdbuf()))
->set_echo(_bool);
}

/* basic_icurses_stream set_keypad */
template <typename charT, typename traits>
void
basic_icurses_stream<charT,traits>::set_keypad(
  bool _bool
){
(static_cast<basic_cursesbuf<charT,traits>*>(this->rdbuf()))
->set_keypad(_bool);
}

/* basic_iocurses_stream ctor */
template <typename charT, typename traits>
basic_iocurses_stream<charT,traits>::basic_iocurses_stream(
  basic_cursesbuf<charT,traits>* _sb
)
	: std::basic_iostream<charT,traits>(_sb){
}

/* basic_iocurses_stream dtor */
template <typename charT, typename traits>
basic_iocurses_stream<charT,traits>::~basic_iocurses_stream(
){
}

/* iocurses_stream rdbuf */
template <typename charT, typename traits>
basic_cursesbuf<charT,traits> *
basic_iocurses_stream<charT,traits>::rdbuf(
) const {
return static_cast<basic_cursesbuf<charT,traits>*>(std::basic_iostream<charT,traits>::rdbuf());
}

/* iocurses_stream set_win */
template <typename charT, typename traits>
typename basic_iocurses_stream<charT,traits>::window_type
basic_iocurses_stream<charT,traits>::set_win(
  typename basic_iocurses_stream<charT,traits>::window_type _index
){
return (static_cast<basic_cursesbuf<charT,traits>*>(this->rdbuf()))
       ->set_win(_index);
}

/* iocurses_stream active_win */
template <typename charT, typename traits>
typename basic_iocurses_stream<charT,traits>::window_type
basic_iocurses_stream<charT,traits>::active_win(
){
return (static_cast<basic_cursesbuf<charT,traits>*>(this->rdbuf()))
       ->active_win();
}

/* iocurses_stream set_cbreak */
template <typename charT, typename traits>
void
basic_iocurses_stream<charT,traits>::set_cbreak(
  bool _bool
){
(static_cast<basic_cursesbuf<charT,traits>*>(this->rdbuf()))
->set_cbreak(_bool);
}

/* iocurses_stream set_echo */
template <typename charT, typename traits>
void
basic_iocurses_stream<charT,traits>::set_echo(
  bool _bool
){
(static_cast<basic_cursesbuf<charT,traits>*>(this->rdbuf()))
->set_echo(_bool);
}

/* iocurses_stream set_keypad */
template <typename charT, typename traits>
void
basic_iocurses_stream<charT,traits>::set_keypad(
  bool _bool
){
(static_cast<basic_cursesbuf<charT,traits>*>(this->rdbuf()))
->set_keypad(_bool);
}

/* iocurses_stream new_win */
template <typename charT, typename traits>
typename basic_iocurses_stream<charT,traits>::window_type
basic_iocurses_stream<charT,traits>::new_win(
  int _lines
, int _cols
, int _y
, int _x
){
return (static_cast<basic_cursesbuf<charT,traits>*>(
         std::basic_ostream<charT,traits>::rdbuf())
       )->new_win(_lines, _cols, _y, _x);
}

/* iocurses_stream del_win */
template <typename charT, typename traits>
void
basic_iocurses_stream<charT,traits>::del_win(
  basic_iocurses_stream<charT,traits>::window_type _index
){
(static_cast<basic_cursesbuf<charT,traits>*>(this->rdbuf()))->del_win(_index);
}

/* iocurses_stream set_border */
template <typename charT, typename traits>
void
basic_iocurses_stream<charT,traits>::set_border(
  charT _left
, charT _right
, charT _top
, charT _bottom
, charT _00c
, charT _01c
, charT _10c
, charT _11c
){
(static_cast<basic_cursesbuf<charT,traits>*>(this->rdbuf()))
->set_border(_left, _right, _top, _bottom, _00c, _01c, _10c, _11c);
}

} /* curstream */
#endif
