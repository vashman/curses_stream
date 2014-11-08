Curses Stream Tutorial
==========================================================================

1 Table of Contents
==========================================================================
1. Table of Contents
2. Introduction
3. Creating the Stream
4. Windows
  1. Creating a Window
  2. Setting a Window
  3. Deleting a Window
  4. Setting window border

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

4 Windows
==========================================================================
1 Creating a Window
--------------------------------------------------------------------------
[example: window.cpp](../example/window.cpp)

```c++
strm.new_win(0,0,0,0);
```
2 Setting a Window
--------------------------------------------------------------------------
[example: window.cpp](../example/window.cpp)

```c++
```

3 Deleting a Window
--------------------------------------------------------------------------
[example: window.cpp](../example/window.cpp)

```c++
```

4 Setting window border
--------------------------------------------------------------------------
[example: window.cpp](../example/window.cpp)

```c++
```
