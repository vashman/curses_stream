
//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef CURSTREAM_CURSESBUF_HPP
#define CURSTREAM_CURSESBUF_HPP

extern "C"{
#include <ncurses.h>
}
#include <ios>
#include <streambuf>
#include <vector>

namespace curstream {

template <typename CharT, typename traits = std::char_traits<CharT> >
class basic_cursesbuf : public std::basic_streambuf<CharT>{
public:
  basic_cursesbuf();

  ~basic_cursesbuf();

  size_t
  new_win(int,int,int,int);

  /* set_win
  set window return previous window id.
  */
  std::size_t
  set_win(
    std::size_t
  );

  void
  del_win(
    std::size_t
  );

  std::size_t
  total_win();

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
    CharT
  , CharT
  , CharT
  , CharT
  , CharT
  , CharT
  , CharT
  , CharT
  );
//	virtual streamsize showmanyc();
//	virtual void imbue(const locale&);
//	virtual basic_streambuf* setbuf();

  virtual typename std::basic_streambuf<CharT,traits>::pos_type
  seekoff(
    typename std::basic_streambuf<CharT, traits>::off_type
  , std::ios_base::seekdir
  , std::ios_base::openmode
  );

  virtual typename std::basic_streambuf<CharT,traits>::pos_type
  seekpos(
    typename std::basic_streambuf<CharT, traits>::off_type
  , std::ios_base::openmode
  );

// always fails virtual typename basic_streambuf<CharT,traits>::int_type pbackfail(typename basic_streambuf<CharT, traits>::int_type c = typename basic_streambuf<CharT, traits>::traits_type::eof());

  virtual typename std::basic_streambuf<CharT,traits>::int_type
  sync();

  virtual typename std::basic_streambuf<CharT,traits>::int_type
  overflow(
    typename std::basic_streambuf<CharT, traits>::int_type
  );

  virtual std::streamsize
  xsputn(
    typename std::basic_streambuf<CharT,traits>::char_type *
  , std::streamsize
  );

  virtual typename std::basic_streambuf<CharT,traits>::int_type
  underflow();

  virtual typename std::basic_streambuf<CharT,traits>::int_type
  uflow();

  virtual std::streamsize
  xsgetn(
    typename std::basic_streambuf<CharT,traits>::char_type *
  , std::streamsize
  );

private:
	static std::size_t active;

	std::vector<WINDOW*> windows;

	std::size_t active_win;
};

typedef basic_cursesbuf<char> cursesbuf;
} /* curstream */
#include "bits/cursesbuf.tcc"
#endif