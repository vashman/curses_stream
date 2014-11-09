// c++ stream implementing curses like interface and functionality.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef CURSTREAM_CURSES_STREAM_HPP
#define CURSTREAM_CURSES_STREAM_HPP

#include <iostream>
#include "cursesbuf.hpp"

namespace curstream {

template <typename charT, typename traits = std::char_traits<charT> >
class basic_ocurses_stream : public std::basic_ostream<charT,traits>{
public:
  typedef basic_cursesbuf<charT,traits>::window_type window_type;

  basic_ocurses_stream(
    basic_cursesbuf<charT,traits> * _buf
         = new basic_cursesbuf<charT,traits>()
  );

  ~basic_ocurses_stream();

  basic_cursesbuf<charT,traits> *
  rdbuf() const;

  window_type
  set_win(
    window_type
  );

  window_type
  new_win(
    int
  , int
  , int
  , int
  );

  void
  del_win(
    window_type
  );

  window_type
  active_win();

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

private:
	//basic_ostream<charT,traits>::basic_streambuf<charT>* rdbuf(basic_streambuf<charT>*);
};

template <typename charT, typename traits = std::char_traits<charT> >
class basic_icurses_stream : public std::basic_istream<charT,traits>{
public:
  typedef basic_cursesbuf<charT,traits>::window_type window_type;

  basic_icurses_stream(
    basic_cursesbuf<charT,traits> * _buf
        = new basic_cursesbuf<charT,traits>()
  );

  ~basic_icurses_stream();

  basic_cursesbuf<charT,traits> *
  rdbuf() const;

  window_type
  set_win(
    window_type
  );

  window_type
  active_win();

  void
  set_cbreak(
    bool _bool = true
  );

  void
  set_echo(
    bool _bool = true
  );

  void
  set_keypad(
    bool _bool = true
  );
};

template <typename charT, typename traits = std::char_traits<charT> >
class basic_iocurses_stream : public std::basic_iostream<charT,traits>{
public:
  typedef basic_cursesbuf<charT,traits>::window_type window_type;

  basic_iocurses_stream(
    basic_cursesbuf<charT,traits> * _sb
         = new basic_cursesbuf<charT,traits>()
  );

  ~basic_iocurses_stream();

  basic_cursesbuf<charT,traits> *
  rdbuf() const;

  window_type
  set_win(
    window_type
  );

  window_type
  active_win();

  void
  set_cbreak(
    bool _bool = true
  );

  void
  set_echo(
    bool _bool = true
  );

  void
  set_keypad(
    bool _bool = true
  );

  window_type
  new_win(
    int
  , int
  , int
  , int
  );

  void
  del_win(
    window_type
  );

  void
  set_border(charT,charT,charT,charT,charT,charT,charT,charT);
};

typedef basic_ocurses_stream<char> ocurses_stream;
typedef basic_icurses_stream<char> icurses_stream;
typedef basic_iocurses_stream<char> curses_stream;

} /* curstream */
#include "bits/curses_stream.tcc"
#endif
