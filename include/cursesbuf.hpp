
//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef CURSES_STREAM_NCURSESBUF_HPP
#define CURSES_STREAM_NCURSESBUF_HPP

extern "C"{
#include <ncurses.h>
}
#include <ios>
#include <streambuf>
#include <vector>

namespace curses_stream {

template <typename charT, typename traits = std::char_traits<charT> >
class basic_cursesbuf : public basic_streambuf<charT>{
public:
  basic_cursesbuf();

  ~basic_cursesbuf();

  size_t
  new_win(int,int,int,int);

  size_t
  set_win(size_t);// set window return previous window id.

  void
  del_win(size_t);

  size_t
  total_win();

  void
  set_cbreak(bool);

  void
  set_echo(bool);

  void
  set_keypad(bool);

  void
  set_border(charT, charT, charT, charT, charT, charT, charT, charT);
//	virtual streamsize showmanyc();
//	virtual void imbue(const locale&);
//	virtual basic_streambuf* setbuf();

  virtual typename std::basic_streambuf<charT,traits>::pos_type
  seekoff(
    typename std::basic_streambuf<charT, traits>::off_type
  , ios_base::seekdir, ios_base::openmode
  );

  virtual typename std::basic_streambuf<charT,traits>::pos_type
  seekpos(
    typename std::basic_streambuf<charT, traits>::off_type
  , ios_base::openmode
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
    typename std::basic_streambuf<charT,traits>::char_type *
  , std::streamsize
  );

  virtual typename std::basic_streambuf<charT,traits>::int_type
  underflow();

  virtual typename std::basic_streambuf<charT,traits>::int_type
  uflow();

  virtual std::streamsize
  xsgetn(
    typename std::basic_streambuf<charT,traits>::char_type *
  , streamsize
  );

private:
	static std::size_t active;

	std::vector<WINDOW*> windows;

	std::size_t active_win;
};

typedef basic_cursesbuf<char> cursesbuf;
} /* curses_stream */
#include "bits/cursesbuf.tcc"
#endif
