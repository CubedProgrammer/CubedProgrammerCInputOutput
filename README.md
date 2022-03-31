# CubedProgrammerCInputOutput
C Streams Library

## Installation Instructions
Download or clone the repository. Put it in a folder on your hard drive.

On Mac OS X, linux, BSD, or any Unix-based system, copy the headers into /usr/local/include.

Compiler flags.

-I or /I, for gcc or clang, and msvc respectively, and then use paths C:/Path/To/The/Library/CubedProgrammerCInputOutput/lib C:/Path/To/The/Library/CubedProgrammerCInputOutput/header_only_include, both are required, on windows.
```
gcc -O3 -I./include -I./header_only_include -c src/cpcio_fstream.c src/cpcio_istream.c src/cpcio_ostream.c src/cpcio_sstream.c src/cpcio_stdstream.c -fPIC
gcc -shared -o libcpcio.so cpcio_fstream.o cpcio_istream.o cpcio_ostream.o cpcio_sstream.o cpcio_stdstream.o -lm
```
or
```
clang -O3 -I./include -I./header_only_include -c src/cpcio_fstream.c src/cpcio_istream.c src/cpcio_ostream.c src/cpcio_sstream.c src/cpcio_stdstream.c -fPIC
clang -shared -o libcpcio.so cpcio_fstream.o cpcio_istream.o cpcio_ostream.o cpcio_sstream.o cpcio_stdstream.o -lm
```
## cpcio_istream
File: cpcio_istream.h
### Structures
struct cpcio\_\_\_\_istream

cpcio_istream (aka struct cpcio\_\_\_\_istream*)

eof flag for cpcio_istream indicates if the eof has been reached, is->eof is true if eof has been reached.
### Functions
#### cpcio_close_istream(is)
Param is is a cpcio_istream.

Closes a cpcio_istream, returns zero on success.
#### cpcio_open_istream(src,reader,close)
Param src is a void pointer, data will be read from it in some way.

Param reader is a pointer to a function, it will return the number of chars read and take in three parameters.
The first parameter is a void pointer, which will be src.
The second parameter is a char pointer, an array to store read chars in.
The third parameter is a size type, the length of the array and the number of chars to try to read.

Param close is a pointer to a function, it must return zero on success, and take in a void pointer as a parameter, which will be src.

Opens a cpcio_istream.
#### cpcio_rd(is,buf,sz)
Param is is a cpcio_istream.

Param buf is a void pointer to a buffer, the data will be written to it.

Param sz is the number of bytes to read.

Reads up to sz bytes and returns the number of bytes read, stores the data in buf.
#### cpcio_toggle_buf_is(is)
Toggles whether or not to use buffered input.

This should only be used to disable buffering before reading any input, or enabling buffering.

Disabling buffering may cause any unread data in the buffer to become lost.
#### cpcio_getc_is(is)
Param is is a cpcio_istream.

Reads a single character from the stream, or 0xff if eof has been reached.
#### cpcio_ungetc_is(is)
Puts the last read character back, only works if buffer is available.
#### cpcio_gtoken_is(is)
Param is is a cpcio_istream.

Reads a token from the stream, returns an empty string if eof has been reached.
#### cpcio_use_delim(is,s)
Param is is a cpcio_istream.

Param s is the delim to use.

Sets the delimiter for token based input
#### cpcio_get_delim(is)
Param is is a cpcio_istream.

Gets the delimiter.
#### cpcio_gint_is(is)
Param is is a cpcio_istream.

Reads an int from the stream.
#### cpcio_glong_is(is)
Param is is a cpcio_istream.

Reads a long from the stream.
#### cpcio_gll_is(is)
Param is is a cpcio_istream.

Reads a long long from the stream.
#### cpcio_gull_is(is)
Param is is a cpcio_istream.

Reads an unsigned long long from the stream.
#### cpcio_gfloat_is(is)
Param is is a cpcio_istream.

Reads a float from the stream.
#### cpcio_gdouble_is(is)
Param is is a cpcio_istream.

Reads a double from the stream
#### cpcio_istream_ready(is)
Checks if there are bytes ready to read.

If return value is true, then there is data to read.

Otherwise, either end of stream has been reached or the stream has to wait for data to be sent.
## cpcio_ostream
File: cpcio_ostream.h
### Structures
struct cpcio\_\_\_\_ostream

cpcio_ostream (aka struct cpcio\_\_\_\_ostream*)
### Functions
#### cpcio_flush_os(os)
Param os is a cpcio_ostream.

Flushes the cpcio_ostream.
#### cpcio_close_ostream(os)
Param os is a cpcio_ostream.

Closes the stream, returns zero if successful.
#### cpcio_open_ostream(src,writer,close)
Param src is a void pointer, data will be written to it in some way.

Param writer is a pointer to a function, it will return the number of chars written and take in three parameters.
The first parameter is a void pointer, which will be src.
The second parameter is a char pointer, an array to write.
The third parameter is a size type, the length of the array.

Param close is a pointer to a function, it must return zero on success, and take in a void pointer as a parameter, which will be src.

Opens a cpcio_ostream.
#### cpcio_wr(os,buf,sz)
Param os is a cpcio_ostream.

Param buf is a const void pointer to a buffer, the data that will be written.

Param sz is the number of bytes to write.

Writes up to sz bytes and returns the number of bytes written.
#### cpcio_toggle_buf_os(os)
Toggles whether or not to buffer the output.

Toggling off will cause the buffer to be flushed.
#### cpcio_putc_os(os,c)
Param os is a cpcio_ostream.

Writes a single charater to the cpcio_ostream.
#### cpcio_puts_os(os,s)
Param os is a cpcio_ostream.

Prints a string to the cpcio_ostream.
#### cpcio_putln_os(os,s)
Param os is a cpcio_ostream.

Prints a string to the cpcio_ostream with a \\n.
#### cpcio_psqln_os(os,begin,end)
Param os is a cpcio_ostream.

Params begin and end are iterators that point to strings.

Prints the sequence to a cpcio_ostream, each item is space separated, and a \\n is put at the end.
#### cpcio_putint_os(os,i)
Param os is a cpcio_ostream.

Param i is an int.

Prints an int to the cpcio_ostream.
#### cpcio_putl_os(os,l)
Param os is a cpcio_ostream.

Param l is a long.

Prints a long to the cpcio_ostream.
#### cpcio_putll_os(os,ll)
Param os is a cpcio_ostream.

Param ll is a long long.

Prints a long long to the cpcio_ostream.
#### cpcio_putull_os(os,ull)
Param os is a cpcio_ostream.

Param ull is a unsigned long long.

Prints an unsigned long long to the cpcio_ostream.
#### cpcio_putf_os(os,f)
Param os is a cpcio_ostream.

Param f is a float.

Prints a float to the cpcio_ostream.
#### cpcio_putd_os(os,d)
Param os is a cpcio_ostream.

Param d is a double.

Prints a double to the cpcio_ostream.

#### cpcio_plnint_os(os,i)
Param os is a cpcio_ostream.

Param i is an int.

Prints an int to the cpcio_ostream with a new line.
#### cpcio_plnl_os(os,l)
Param os is a cpcio_ostream.

Param l is a long.

Prints a long to the cpcio_ostream with a new line.
#### cpcio_plnll_os(os,ll)
Param os is a cpcio_ostream.

Param ll is a long long.

Prints a long long to the cpcio_ostream with a new line.
#### cpcio_plnull_os(os,ull)
Param os is a cpcio_ostream.

Param ull is a unsigned long long.

Prints an unsigned long long to the cpcio_ostream with a new line.
#### cpcio_plnf_os(os,f)
Param os is a cpcio_ostream.

Param f is a float.

Prints a float to the cpcio_ostream with a new line.
#### cpcio_plnd_os(os,d)
Param os is a cpcio_ostream.

Param d is a double.

Prints a double to the cpcio_ostream with a new line.

## cpcio_sstream
File: cpcio_sstream.h

String streams header. There are input string streams and output string streams.
### Structures
This header does offer new structs but they are not important for the user to know.
### Functions
#### cpcio_open_isstream(str)
Param str is a string to read from.

Opens an istringstream that reads from a string.
#### cpcio_open_isstream_arr(arr,n)
Param arr is a char array.

Param n is the size of the array.

Opens an istringstream that reads from a string.
#### cpcio_open_osstream(void)
Opens a ostringstream that writes to a string.
#### cpcio_oss_str(oss)
Param oss is a pointer to an ostringstream.

Gets the string from the ostringstream.
## cpcio_fstream
File: cpcio_fstream.h

File streams header, for reading and writing to files.
### Structures
This header does not offer any structs.
### Functions
#### cpcio_open_ifstream(s)
Param s is the file name.

Opens a cpcio_istream that reads from a file.
#### cpcio_open_ofstream(s,m)
Param s is a filename.

Param m is the mode, either w for write or a for append.

Opens a cpcio_ostream that writes to a file.
## cpcio_stdstream
File: cpcio_stdstream.h

File streams header, for reading and writing to files.
### Structures
This header does not offer any structs.
### Functions
#### cpcio_get_stdin(void)
Gets a cpcio_istream that reads from stdin.
#### cpcio_get_stdout(void)
Gets a cpcio_ostream that reads from stdout.
#### cpcio_get_stderr(void)
Gets a cpcio_ostream that reads from stderr.