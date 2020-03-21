# CubedProgrammerCInputOutput
C Streams Library
## istream
File: istream.h
### Structures
struct \_\_istream

istream (aka struct \_\_istream*)
### Functions
#### closeis(is)
Param is is an istream.
Closes an istream, returns zero on success.
#### openis(f)
Param f is a FILE pointer.

Opens an istream that reads from the FILE pointer.
#### openifs(s)
Param s is the file name.

Opens an istream that reads from a file.
#### cpcio_getc_is(is)
Param is is an istream.

Reads a single character from the stream.
#### cpcio_gtoken_is(is)
Param is is an istream.

Reads a token from the stream.
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
struct \_\_ostream

ostreeam (aka struct \_\_ostream*)
### Functions
#### cpcio_flush_os(os)
Param os is an ostream.

Flushes the ostream.
#### closeos(os)
Param os is an ostream.

Closes the stream, returns zero if successful.
#### openos(f)
Param f is a FILE pointer

Opens an ostream that writes to the FILE pointer.
#### openofs(s)
Param s is a filename.

Opens an ostream that writes to a file.
#### openofsa(s)
Param s is a filename.

Opens an ostream that appends to a file.
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
#### cpcio_plni_os(os,i)
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
