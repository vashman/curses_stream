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

template <typename CharT, typename traits = std::char_traits<CharT> >
class basic_ocurses_stream : public std::basic_ostream<CharT,traits>{
public:
  basic_ocurses_stream(
    basic_cursesbuf<CharT,traits> * _buf
         = new basic_cursesbuf<CharT,traits>()
  );

  ~basic_ocurses_stream();

  basic_cursesbuf<CharT,traits> *
  rdbuf() const;

  void
  set_win(
    std::size_t
  );

  void
  new_win(
    int
  , int
  , int
  , int
  );

  void
  del_win(
    std::size_t
  );

  std::size_t
  total_win();

  void
  set_border(
    CharT
  , CharT
  , CharT
  , CharT
  , CharT
  , CharT
  , CharT
  , CharT
  );

private:
	//basic_ostream<CharT,traits>::basic_streambuf<CharT>* rdbuf(basic_streambuf<CharT>*);
};

template <typename CharT, typename traits = std::char_traits<CharT> >
class basic_icurses_stream : public std::basic_istream<CharT,traits>{
public:
  basic_icurses_stream(
    basic_cursesbuf<CharT,traits> * _buf
        = new basic_cursesbuf<CharT,traits>()
  );

  ~basic_icurses_stream();

  basic_cursesbuf<CharT,traits> *
  rdbuf() const;

  void
  set_win(
    std::size_t
  );

  std::size_t
  total_win();

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

template <typename CharT, typename traits = std::char_traits<CharT> >
class basic_iocurses_stream : public std::basic_iostream<CharT,traits>{
public:
  basic_iocurses_stream(
    basic_cursesbuf<CharT,traits> * _sb
         = new basic_cursesbuf<CharT,traits>()
  );

  ~basic_iocurses_stream();

  basic_cursesbuf<CharT,traits> *
  rdbuf() const;

  void
  set_win(
    std::size_t
  );

  std::size_t
  total_win();

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

  void
  new_win(
    int
  , int
  , int
  , int
  );

  void
  del_win(
    std::size_t
  );

  void
  set_border(CharT,CharT,CharT,CharT,CharT,CharT,CharT,CharT);
};

typedef basic_ocurses_stream<char> ocurses_stream;
typedef basic_icurses_stream<char> icurses_stream;
typedef basic_iocurses_stream<char> curses_stream;

} /* curstream */
#include "bits/curses_stream.tcc"
#endif
