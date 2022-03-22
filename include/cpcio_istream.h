#ifndef __cplusplus
#ifndef Included_cpcio_istream_h
#define Included_cpcio_istream_h
#ifndef CPCIO____BUFSZ
#define CPCIO____BUFSZ 16384
#endif
#ifndef CPCIO____MAX_DELIM_SIZE
#define CPCIO____MAX_DELIM_SIZE 100
#endif
#include<stdbool.h>
#include<stdio.h>
// the istream structure
// src is the thing that is read from
// rd is for reading, the src is passed in
// and it must read chars into the buffer
// close function is called when the stream is closed
struct cpcio____istream
{
	void*src;
	int(*rd)(void*,char*,size_t);
	int(*close)(void*);
	int(*ready)(void*);
	bool eof;
	bool ubuf;
	short last;
	char cbuf[CPCIO____BUFSZ];
	unsigned short bufs;
	char delim[CPCIO____MAX_DELIM_SIZE];
	unsigned short delimsz;
};
int cpcio_close_istream(struct cpcio____istream*);
struct cpcio____istream*cpcio_open_istream(void*,int(*)(void*,char*,size_t),int(*)(void*));
size_t cpcio_rd(struct cpcio____istream*,void*,size_t);
void cpcio_toggle_buf_is(struct cpcio____istream*);
int cpcio_getc_is(struct cpcio____istream*);
void cpcio_ungetc_is(struct cpcio____istream*);
char*cpcio_gtoken_is(struct cpcio____istream*);
void cpcio_use_delim(struct cpcio____istream*,const char*);
char*cpcio_get_delim(struct cpcio____istream*);
int cpcio_gint_is(struct cpcio____istream*);
long cpcio_glong_is(struct cpcio____istream*);
long long cpcio_gll_is(struct cpcio____istream*);
unsigned long long cpcio_gull_is(struct cpcio____istream*);
float cpcio_gfloat_is(struct cpcio____istream*);
double cpcio_gdouble_is(struct cpcio____istream*);
int cpcio_istream_ready(struct cpcio____istream*);
void*cpcio_src_is(struct cpcio____istream*);
typedef struct cpcio____istream*cpcio_istream;
typedef struct cpcio____istream*istream;
#endif
#endif
