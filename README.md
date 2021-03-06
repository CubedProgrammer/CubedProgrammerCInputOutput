# CubedProgrammerCInputOutput
C Streams Library

## Installation Instructions
Download or clone the repository. Put it in a folder on your hard drive.

Compiler flags.

-I or /I, for gcc and msvc respectively, and then use paths C:/Path/To/The/Library/CubedProgrammerCInputOutput/lib C:/Path/To/The/Library/CubedProgrammerCInputOutput/header_only_include, both are required

gcc -O3 -I./include -I./header_only_include -c include/cpcio_impl/fstream_impl.c -fPIC

gcc -O3 -I./include -I./header_only_include -c include/cpcio_impl/istream_impl.c -fPIC

gcc -O3 -I./include -I./header_only_include -c include/cpcio_impl/ostream_impl.c -fPIC

gcc -O3 -I./include -I./header_only_include -c include/cpcio_impl/sstream_impl.c -fPIC

gcc -shared -o libcpcio.so fstream_impl.o istream_impl.o ostream_impl.o sstream_impl.o
## istream
File: istream.h
### Structures
struct cpcio\_\_\_\_istream

istream (aka struct cpcio\_\_\_\_istream*)

eof flag for istream indicates if the eof has been reached, is->eof is true if eof has been reached.
### Functions
#### cpcio_close_istream(is)
Param is is an istream.

Closes an istream, returns zero on success.
#### cpcio_open_istream(src,reader,close)
Param src is a void pointer, data will be read from it in some way.

Param reader is a pointer to a function, it will return the number of chars read and take in three parameters.
The first parameter is a void pointer, which will be src.
The second parameter is a char pointer, an array to store read chars in.
The third parameter is a size type, the length of the array and the number of chars to try to read.

Param close is a pointer to a function, it must return zero on success, and take in a void pointer as a parameter, which will be src.

Opens an istream.
#### cpcio_getc_is(is)
Param is is an istream.

Reads a single character from the stream, or 0xff if eof has been reached.
#### cpcio_gtoken_is(is)
Param is is an istream.

Reads a token from the stream, returns an empty string if eof has been reached.
#### cpcio_use_delim(is,s)
Param is is an istream.

Param s is the delim to use.

Sets the delimiter for token based input
#### cpcio_get_delim(is)
Param is is an istream.

Gets the delimiter.
#### cpcio_gint_is(is)
Param is is an istream.

Reads an int from the stream.
#### cpcio_glong_is(is)
Param is is an istream.

Reads a long from the stream.
#### cpcio_gll_is(is)
Param is is an istream.

Reads a long long from the stream.
#### cpcio_gull_is(is)
Param is is an istream.

Reads an unsigned long long from the stream.
#### cpcio_gfloat_is(is)
Param is is an istream.

Reads a float from the stream.
#### cpcio_gdouble_is(is)
Param is is an istream.

Reads a double from the stream
## ostream
File: ostream.h
### Structures
struct cpcio\_\_\_\_ostream

ostream (aka struct cpcio\_\_\_\_ostream*)
### Functions
#### cpcio_flush_os(os)
Param os is an ostream.

Flushes the ostream.
#### cpcio_close_ostream(os)
Param os is an ostream.

Closes the stream, returns zero if successful.
#### cpcio_open_ostream(src,writer,close)
Param src is a void pointer, data will be written to it in some way.

Param writer is a pointer to a function, it will return the number of chars written and take in three parameters.
The first parameter is a void pointer, which will be src.
The second parameter is a char pointer, an array to write.
The third parameter is a size type, the length of the array.

Param close is a pointer to a function, it must return zero on success, and take in a void pointer as a parameter, which will be src.

Opens an ostream.
#### openofs(s,m)
Param s is a filename.

Param m is the mode, either w for write or a for append.

Opens an ostream that writes to a file.
#### cpcio_putc_os(os,c)
Param os is an ostream.

Writes a single charater to the ostream.
#### cpcio_puts_os(os,s)
Param os is an ostream.

Prints a string to the ostream.
#### cpcio_putln_os(os,s)
Param os is an ostream.

Prints a string to the ostream with a \\n.
#### cpcio_psqln_os(os,begin,end)
Param os is an ostream.

Params begin and end are iterators that point to strings.

Prints the sequence to an ostream, each item is space separated, and a \\n is put at the end.
#### cpcio_putint_os(os,i)
Param os is an ostream.

Param i is an int.

Prints an int to the ostream.
#### cpcio_putl_os(os,l)
Param os is an ostream.

Param l is a long.

Prints a long to the ostream.
#### cpcio_putll_os(os,ll)
Param os is an ostream.

Param ll is a long long.

Prints a long long to the ostream.
#### cpcio_plnull_os(os,ull)
Param os is an ostream.

Param ull is a unsigned long long.

Prints an unsigned long long to the ostream.
#### cpcio_putf_os(os,f)
Param os is an ostream.

Param f is a float.

Prints a float to the ostream.
#### cpcio_putd_os(os,d)
Param os is an ostream.

Param d is a double.

Prints a double to the ostream.

#### cpcio_plnint_os(os,i)
Param os is an ostream.

Param i is an int.

Prints an int to the ostream with a new line.
#### cpcio_plnl_os(os,l)
Param os is an ostream.

Param l is a long.

Prints a long to the ostream with a new line.
#### cpcio_plnll_os(os,ll)
Param os is an ostream.

Param ll is a long long.

Prints a long long to the ostream with a new line.
#### cpcio_plnull_os(os,ull)
Param os is an ostream.

Param ull is a unsigned long long.

Prints an unsigned long long to the ostream with a new line.
#### cpcio_plnf_os(os,f)
Param os is an ostream.

Param f is a float.

Prints a float to the ostream with a new line.
#### cpcio_plnd_os(os,d)
Param os is an ostream.

Param d is a double.

Prints a double to the ostream with a new line.

## sstream
File: sstream.h

String streams header. There are input string streams and output string streams.
### Structures
This header does offer new structs but they are not important for the user to know.
### Functions
#### cpcio_open_isstream(str)
Param str is a string to read from.

Opens an istringstream that reads from a string.
#### cpcio_open_osstream()
Opens a ostringstream that writes to a string.
#### cpcio_oss_str(oss)
Param oss is a pointer to an ostringstream.

Gets the string from the ostringstream.
## fstream
File: fstream.h

File streams header, for reading and writing to files.
### Structures
This header does not offer any structs.
### Functions
#### cpcio_open_ifstream(s)
Param s is the file name.

Opens an istream that reads from a file.
#### cpcio_open_ofstream(s,m)
Param s is a filename.

Param m is the mode, either w for write or a for append.

Opens an ostream that writes to a file.
