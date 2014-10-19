Curses Stream Tutorial
==========================================================================

1 Table of Contents
==========================================================================
1. Table of Contents
2. Introduction

2 Introduction
==========================================================================
curses stream is a c++ io stream with curses features. This implementation
is simply a wrapper around the ncurses library.

3 Creating the Stream
==========================================================================
[example: create.cpp](../example/create.cpp)

```c++
curses_stream io;
/* same as above, notice how creating a second instance does not start
another session over the terminal but shares it with the previous.
*/
curses_stream io2(new cursesbuf());
```
