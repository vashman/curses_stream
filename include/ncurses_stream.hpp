
//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef STDL_NCURSES_STREAM_HPP
#define STDL_NCURSES_STREAM_HPP

#include <iostream>
#include "ncursesbuf.hpp"

namespace stdl{
using std::basic_iostream;
using std::basic_ostream;
using std::basic_istream;
using stdl::basic_ncursesbuf;
using std::basic_streambuf;
using std::char_traits;

template <typename charT, typename traits = char_traits<charT> >
class basic_oncurses_stream : public basic_ostream<charT,traits>{
public:
	basic_oncurses_stream(basic_ncursesbuf<charT,traits>* _buf = new basic_ncursesbuf<charT,traits>());
	~basic_oncurses_stream();
	basic_ncursesbuf<charT,traits>* rdbuf() const;
	void set_win(size_t);
	void new_win(int,int,int,int);
	void del_win(size_t);
	size_t total_win();
	void set_border(charT,charT,charT,charT,charT,charT,charT,charT);
private:
	//basic_ostream<charT,traits>::basic_streambuf<charT>* rdbuf(basic_streambuf<charT>*);
};

template <typename charT, typename traits = char_traits<charT> >
class basic_incurses_stream : public basic_istream<charT,traits>{
public:
	basic_incurses_stream(basic_ncursesbuf<charT,traits>* _buf = new basic_ncursesbuf<charT,traits>());
	~basic_incurses_stream();
	basic_ncursesbuf<charT,traits>* rdbuf() const;
	void set_win(size_t);
	size_t total_win();
	void set_cbreak(bool _bool = true);
	void set_echo(bool _bool = true);
	void set_keypad(bool _bool = true);
};

template <typename charT, typename traits = char_traits<charT> >
class basic_ioncurses_stream : public basic_iostream<charT,traits>{
public:
	basic_ioncurses_stream(basic_ncursesbuf<charT,traits>* _sb = new basic_ncursesbuf<charT,traits>());
	~basic_ioncurses_stream();
	basic_ncursesbuf<charT,traits>* rdbuf() const;
	void set_win(size_t);
	size_t total_win();
	void set_cbreak(bool _bool = true);
	void set_echo(bool _bool = true);
	void set_keypad(bool _bool = true);
	void new_win(int,int,int,int);
	void del_win(size_t);
	void set_border(charT,charT,charT,charT,charT,charT,charT,charT);
};

// # ostream
template <typename charT, typename traits>
basic_oncurses_stream<charT,traits>::basic_oncurses_stream(basic_ncursesbuf<charT,traits>* _buf)
	: basic_ostream<charT,traits>(_buf){
}

template <typename charT, typename traits>
basic_oncurses_stream<charT,traits>::~basic_oncurses_stream(){
}

template <typename charT, typename traits>
basic_ncursesbuf<charT,traits>* basic_oncurses_stream<charT,traits>::rdbuf() const{
return static_cast<basic_ncursesbuf<charT>*>(basic_ostream<charT,traits>::rdbuf());
}

template <typename charT, typename traits>
void basic_oncurses_stream<charT,traits>::set_win(size_t _win){
auto sb = static_cast<basic_ncursesbuf<charT,traits>*>(basic_ostream<charT,traits>::rdbuf());
sb->set_win(_win);
}

template <typename charT, typename traits>
void basic_oncurses_stream<charT,traits>::new_win(int _lines, int _cols, int _y, int _x){
(static_cast<basic_ncursesbuf<charT,traits>*>(basic_ostream<charT,traits>::rdbuf()))->new_win(_lines, _cols, _y, _x);
}

template <typename charT, typename traits>
void basic_oncurses_stream<charT,traits>::del_win(size_t _index){
(static_cast<basic_ncursesbuf<charT,traits>*>(this->rdbuf()))->del_win(_index);
}

template <typename charT, typename traits>
void basic_oncurses_stream<charT,traits>::set_border(charT _left, charT _right, charT _top, charT _bottom, charT _00c, charT _01c, charT _10c, charT _11c){
(static_cast<basic_ncursesbuf<charT,traits>*>(this->rdbuf()))->set_border(_left, _right, _top, _bottom, _00c, _01c, _10c, _11c);
}

// # istream
template <typename charT, typename traits>
basic_incurses_stream<charT,traits>::basic_incurses_stream(basic_ncursesbuf<charT,traits>* _sb)
	: basic_istream<charT,traits>(_sb){
}

template <typename charT, typename traits>
basic_incurses_stream<charT,traits>::~basic_incurses_stream(){
}

template <typename charT, typename traits>
void basic_incurses_stream<charT,traits>::set_win(size_t _index){
(static_cast<basic_ncursesbuf<charT,traits>*>(this->rdbuf()))->set_win(_index);
}

template <typename charT, typename traits>
size_t basic_incurses_stream<charT,traits>::total_win(){
return (static_cast<basic_ncursesbuf<charT,traits>*>(this->rdbuf()))->totatl_win();
}

template <typename charT, typename traits>
void basic_incurses_stream<charT,traits>::set_cbreak(bool _bool){
(static_cast<basic_ncursesbuf<charT,traits>*>(this->rdbuf()))->set_cbreak(_bool);
}

template <typename charT, typename traits>
void basic_incurses_stream<charT,traits>::set_echo(bool _bool){
(static_cast<basic_ncursesbuf<charT,traits>*>(this->rdbuf()))->set_echo(_bool);
}

template <typename charT, typename traits>
void basic_incurses_stream<charT,traits>::set_keypad(bool _bool){
(static_cast<basic_ncursesbuf<charT,traits>*>(this->rdbuf()))->set_keypad(_bool);
}

// # iostream
template <typename charT, typename traits>
basic_ioncurses_stream<charT,traits>::basic_ioncurses_stream(basic_ncursesbuf<charT,traits>* _sb)
	: basic_iostream<charT,traits>(_sb){
}

template <typename charT, typename traits>
basic_ioncurses_stream<charT,traits>::~basic_ioncurses_stream(){
}

template <typename charT, typename traits>
basic_ncursesbuf<charT,traits>* basic_ioncurses_stream<charT,traits>::rdbuf() const{
return static_cast<basic_ncursesbuf<charT,traits>*>(basic_iostream<charT,traits>::rdbuf());
}

template <typename charT, typename traits>
void basic_ioncurses_stream<charT,traits>::set_win(size_t _index){
(static_cast<basic_ncursesbuf<charT,traits>*>(this->rdbuf()))->set_win(_index);
}

template <typename charT, typename traits>
size_t basic_ioncurses_stream<charT,traits>::total_win(){
return (static_cast<basic_ncursesbuf<charT,traits>*>(this->rdbuf()))->totatl_win();
}

template <typename charT, typename traits>
void basic_ioncurses_stream<charT,traits>::set_cbreak(bool _bool){
(static_cast<basic_ncursesbuf<charT,traits>*>(this->rdbuf()))->set_cbreak(_bool);
}

template <typename charT, typename traits>
void basic_ioncurses_stream<charT,traits>::set_echo(bool _bool){
(static_cast<basic_ncursesbuf<charT,traits>*>(this->rdbuf()))->set_echo(_bool);
}

template <typename charT, typename traits>
void basic_ioncurses_stream<charT,traits>::set_keypad(bool _bool){
(static_cast<basic_ncursesbuf<charT,traits>*>(this->rdbuf()))->set_keypad(_bool);
}

template <typename charT, typename traits>
void basic_ioncurses_stream<charT,traits>::new_win(int _lines, int _cols, int _y, int _x){
(static_cast<basic_ncursesbuf<charT,traits>*>(basic_ostream<charT,traits>::rdbuf()))->new_win(_lines, _cols, _y, _x);
}

template <typename charT, typename traits>
void basic_ioncurses_stream<charT,traits>::del_win(size_t _index){
(static_cast<basic_ncursesbuf<charT,traits>*>(this->rdbuf()))->del_win(_index);
}

template <typename charT, typename traits>
void basic_ioncurses_stream<charT,traits>::set_border(charT _left, charT _right, charT _top, charT _bottom, charT _00c, charT _01c, charT _10c, charT _11c){
(static_cast<basic_ncursesbuf<charT,traits>*>(this->rdbuf()))->set_border(_left, _right, _top, _bottom, _00c, _01c, _10c, _11c);
}

typedef basic_oncurses_stream<char> oncurses_stream;
typedef basic_incurses_stream<char> incurses_stream;
typedef basic_ioncurses_stream<char> ioncurses_stream;
}
#endif
