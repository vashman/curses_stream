// c++ streambuf implementing curses like interface and functionality.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef CURSTREAM_CURSESBUF_HPP
#define CURSTREAM_CURSESBUF_HPP

extern "C"{
#include <ncurses.h>
}
#include <ios>
#include <streambuf>

namespace curstream {

template <typename charT, typename traits = std::char_traits<charT> >
class basic_cursesbuf : public std::basic_streambuf<charT, traits>{
public:
  /* windows are raw pointers to lib structs */
  typedef WINDOW * window_type;

  basic_cursesbuf();

#if __cplusplus >= 201103L
  basic_cursesbuf(
    basic_cursesbuf<charT,traits> const &
  ) = delete;

  basic_cursesbuf &
  operator=(
    basic_cursesbuf<charT,traits> const &
  ) = delete;
#endif

  ~basic_cursesbuf();

  window_type
  new_win(
    int
  , int
  , int
  , int
  );

  window_type
  active_win(
  );

  /* set_win
  set window return previous window id.
  */
  window_type
  set_win(
    window_type
  );

  void
  del_win(
    window_type
  );

  void
  set_cbreak(
    bool
  );

  void
  set_echo(
    bool
  );

  void
  set_keypad(
    bool
  );

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
//	virtual streamsize showmanyc();
//	virtual void imbue(const locale&);
//	virtual basic_streambuf* setbuf();

  virtual typename std::basic_streambuf<charT,traits>::pos_type
  seekoff(
    typename std::basic_streambuf<charT, traits>::off_type
  , std::ios_base::seekdir
  , std::ios_base::openmode
  );

  virtual typename std::basic_streambuf<charT,traits>::pos_type
  seekpos(
    typename std::basic_streambuf<charT, traits>::pos_type
  , std::ios_base::openmode
  );

// always fails virtual typename basic_streambuf<charT,traits>::int_type pbackfail(typename basic_streambuf<charT, traits>::int_type c = typename basic_streambuf<charT, traits>::traits_type::eof());

  virtual typename std::basic_streambuf<charT,traits>::int_type
  sync();

  virtual typename std::basic_streambuf<charT,traits>::int_type
  overflow(
    typename std::basic_streambuf<charT, traits>::int_type
  );

  virtual std::streamsize
  xsputn(
    const typename std::basic_streambuf<charT,traits>::char_type *
  , std::streamsize
  );

  virtual typename std::basic_streambuf<charT,traits>::int_type
  underflow();

  virtual typename std::basic_streambuf<charT,traits>::int_type
  uflow();

  virtual std::streamsize
  xsgetn(
    typename std::basic_streambuf<charT,traits>::char_type *
  , std::streamsize
  );

  static std::size_t active;

  window_type active_win;

  window_type init_win;
};

typedef basic_cursesbuf<char> cursesbuf;

} /* curstream */
#include "bits/cursesbuf.tcc"
#endif
