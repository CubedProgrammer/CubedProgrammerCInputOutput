#ifndef __cplusplus
#ifndef Included_header_only_cpcio_stdstream_h
#define Included_header_only_cpcio_stdstream_h
#include<stdint.h>
#ifdef _WIN32
#include<windows.h>
#else
#include<sys/select.h>
#include<time.h>
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
	DWORD bc;
	ReadFile(src, buf, sz, &bc, NULL);
	return bc;
#else
	return read((intptr_t)src,buf,sz);
#endif
}

// function for writing to stdout and stderr
int cpcio____wr_stdouterr(void*src,const char*buf,size_t sz)
{
#ifdef _WIN32
	DWORD bc;
	WriteFile(src, buf, sz, &bc, NULL);
	return bc;
#else
	return write((intptr_t)src,buf,sz);
#endif
}

// function for closing std streams
int cpcio____close_stdstream(void*src)
{
#ifdef _WIN32
	return CloseHandle(src);
#else
	return close((intptr_t)src);
#endif
}

int cpcio_stdin_ready(void*src)
{
	int ready = 0;
#ifdef _WIN32
#else
		intptr_t fd = (intptr_t)src;
		struct timeval tv;
		tv.tv_sec = 0;
		tv.tv_usec = 0;
		fd_set rfd, *rfdp = &rfd;
		FD_ZERO(rfdp);
		FD_SET(fd, rfdp);
		ready = select(1, rfdp, NULL, NULL, &tv);
#endif
	return ready;
}

struct cpcio____istream*cpcio_get_stdin(void)
{
	if(cpcio_stdin == NULL)
	{
#ifdef _WIN32
		cpcio_stdin = cpcio_open_istream(GetStdHandle(STD_INPUT_HANDLE), cpcio____rd_stdin, cpcio____close_stdstream);
#else
		cpcio_stdin = cpcio_open_istream((void*)STDIN_FILENO, cpcio____rd_stdin, cpcio____close_stdstream);
		cpcio_stdin->ready = &cpcio_stdin_ready;
#endif
	}
	return cpcio_stdin;
}

// get cpcio wrapped stdout
struct cpcio____ostream*cpcio_get_stdout(void)
{
	if(cpcio_stdout == NULL)
#ifdef _WIN32
		cpcio_stdout = cpcio_open_ostream(GetStdHandle(STD_OUTPUT_HANDLE), cpcio____wr_stdouterr, cpcio____close_stdstream);
#else
		cpcio_stdout = cpcio_open_ostream((void*)STDOUT_FILENO, cpcio____wr_stdouterr, cpcio____close_stdstream);
#endif
	return cpcio_stdout;
}

// get cpcio wrapped stderr
struct cpcio____ostream*cpcio_get_stderr(void)
{
	if(cpcio_stderr == NULL)
#ifdef _WIN32
		cpcio_stderr = cpcio_open_ostream(GetStdHandle(STD_ERROR_HANDLE), cpcio____wr_stdouterr, cpcio____close_stdstream);
#else
		cpcio_stderr = cpcio_open_ostream((void*)STDERR_FILENO, cpcio____wr_stdouterr, cpcio____close_stdstream);
#endif
	return cpcio_stderr;
}
#endif
#endif
