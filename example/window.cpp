#include "../include/curses_stream.hpp"

using curstream::cursesbuf;
using curstream::curses_stream;

int main(){
curses_stream io;

/* create a window to save the used window */
typename curses_stream::window_type root_window;
typename curses_stream::window_type window;

/* save the root window */
root_window = io.active_win();

/* create new window at cordinates 0, 0, 0, 0.
Then save window into window variable. */
window = io.new_win(12,7,2,4);

/* set the active window to the new window */
io.set_win(window);

/* set a border around the window */
io.set_border('1','2','3','4','5','6','7','8');
io.sync();

/* delete the window */
//io.set_win(root_window);
//io.del_win(window);

io << "Enter int";
io.sync();

int i;
io >> i;
return 0;
}
