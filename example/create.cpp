#include "../include/curses_stream.hpp"

using curstream::cursesbuf;
using curstream::curses_stream;

int main(){
/* new curses stream */
curses_stream io;

/* same as above, notice how creating a second instance does not start
another session over the terminal but shares it with the previous.
*/
curses_stream io2;

/* create stream by passing cursesbuf */
cursesbuf buf;
curses_stream io3(& buf);
return 0;
}
