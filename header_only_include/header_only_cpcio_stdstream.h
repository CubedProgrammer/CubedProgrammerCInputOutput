#ifndef __cplusplus
#ifndef Included_header_only_cpcio_stdstream_h
#define Included_header_only_cpcio_stdstream_h
#ifdef _WIN32
#include<windows.h>
#else
#include<unistd.h>
#endif
#include<cpcio_stdstream.h>
struct cpcio____istream*cpcio_stdin;
struct cpcio____ostream*cpcio_stdout;
struct cpcio____ostream*cpcio_stderr;

// function for reading from stdin
int cpcio____rd_stdin(void*src,char*buf,size_t sz)
{
#ifdef _WIN32
#else
	return read((int)src,buf,sz);
#endif
}

// function for writing to stdout and stderr
int cpcio____wr_stdouterr(void*src,const char*buf,size_t sz)
{
#ifdef _WIN32
#else
	return write((int)src,buf,sz);
#endif
}

// function for closing std streams
int cpcio____close_stdstream(void*src)
{
#ifdef _WIN32
#else
	return close((int)src);
#endif
}

struct cpcio____istream*cpcio_get_stdin(void)
{
	if(cpcio_stdin == NULL)
		cpcio_stdin = cpcio_open_istream((void*)STDIN_FILENO, cpcio____rd_stdin, cpcio____close_stdstream);
	return cpcio_stdin;
}

// get cpcio wrapped stdout
struct cpcio____ostream*cpcio_get_stdout(void)
{
	if(cpcio_stdout == NULL)
		cpcio_stdout = cpcio_open_ostream((void*)STDOUT_FILENO, cpcio____wr_stdouterr, cpcio____close_stdstream);
	return cpcio_stdout;
}

// get cpcio wrapped stderr
struct cpcio____ostream*cpcio_get_stderr(void)
{
	if(cpcio_stderr == NULL)
		cpcio_stderr = cpcio_open_ostream((void*)STDERR_FILENO, cpcio____wr_stdouterr, cpcio____close_stdstream);
	return cpcio_stderr;
}
#endif
#endif
