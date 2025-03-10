#ifndef __cplusplus
#ifndef Included_header_only_cpcio_istream_h
#define Included_header_only_cpcio_istream_h
#include<stdlib.h>
#include<string.h>
#include<cpcio_istream.h>

// closes the istream
int cpcio_close_istream(struct cpcio____istream*is)
{
	int succ = is->close(is->src);
	free(is);
	return succ;
}

// opens an istream given src
// and pointers to required functions
struct cpcio____istream*cpcio_open_istream(void*src,size_t(*rdr)(void*,void*,size_t),int(*close)(void*))
{
	struct cpcio____istream*is=malloc(sizeof(struct cpcio____istream));
	for(char*it=is->cbuf;it!=is->cbuf+CPCIO____BUFSZ;++it)
	{
		*it=-1;
	}
	for(char*it=is->delim;it!=is->delim+CPCIO____MAX_DELIM_SIZE;++it)
	{
		*it=-1;
	}
	strcpy(is->delim,"\n\t ");
	is->src=src;
	is->rd=rdr;
	is->close=close;
	is->ready=&cpcio_default_ready;
	is->eof=false;
	is->ubuf=true;
	is->bufi=0;
	is->bufs=0;
	is->delimsz=3;
	is->last=0;
	return is;
}

// reads a block of data
// returns the number of bytes read
size_t cpcio_rd(struct cpcio____istream*is,void*buf,size_t sz)
{
	size_t cnt=0;
	if(is->ubuf&&is->bufs>is->bufi)
	{
		cnt=is->bufs-is->bufi;
		cnt=sz<cnt?sz:cnt;
		buf=memcpy(buf,is->cbuf+is->bufi,cnt);
		is->bufi+=cnt;
		sz-=cnt;
	}
	return cnt+is->rd(is->src,buf,sz);
}

// toggle use buffer or not
void cpcio_toggle_buf_is(struct cpcio____istream*is)
{
	is->ubuf = !is->ubuf;
}

// returns non-zero if end of stream is reached, zero if not
int cpcio_eof_is(struct cpcio____istream*is)
{
	return is->eof;
}

// gets one character
// or -1 if eof is reached
int cpcio_getc_is(struct cpcio____istream*is)
{
	if(is->eof)
	{
		return-1;
	}
	else if(!is->ubuf)
	{
		char ch;
		return is->rd(is->src,&ch,1) == 0 ? -1 : ch;
	}
	else if(is->bufi<is->bufs)
	{
		char c=is->cbuf[is->bufi];
		++is->bufi;
		return c;
	}
	else if(is->last > 0xff)
	{
		char c=is->last;
		is->last&=0xff;
		return c;
	}
	else
	{
		is->last = is->cbuf[CPCIO____BUFSZ - 1] == -1 ? 0 : is->cbuf[CPCIO____BUFSZ - 1];
		is->bufs=is->rd(is->src,is->cbuf,CPCIO____BUFSZ);
		if(is->bufs==0)
		{
			is->bufi=0;
			is->bufs=0;
			is->eof=true;
		}
		else
		{
			is->bufi=1;
		}
		return is->bufs==0?-1:*is->cbuf;
	}
}

// ungets a character
// basically, the last character read is un-read
void cpcio_ungetc_is(struct cpcio____istream *is)
{
	if(is->bufs == 0)
		is->last += 1 << 8;
	else
		--is->bufs;
}

// reads a token based on delimiters
// returns it as a heap allocated null-terminated string
char*cpcio_gtoken_is(struct cpcio____istream*is)
{
	return cpcio_gtoken_save_is(is,0);
}

// reads a token based on delimiters
// if save is true, then the delimiter is also saved into the string
// returns it as a heap allocated null-terminated string
char*cpcio_gtoken_save_is(struct cpcio____istream*is, int save)
{
	int ch=cpcio_getc_is(is);
	int delim=0;
	char*tmp=(char*)malloc(CPCIO____BUFSZ*sizeof(char));
	size_t as=CPCIO____BUFSZ;
	size_t ts=0;
	while(!delim)
	{
		for(size_t i=0;i<is->delimsz;i++)
		{
			if(is->delim[i]==ch)
			{
				delim=is->delim[i];
			}
		}
		if(ch==-1)
		{
			delim=-1;
		}
		if(delim!=-1&&(!delim||save))
		{
			if(ts==as)
			{
				tmp=realloc(tmp,as+CPCIO____BUFSZ);
			}
			tmp[ts]=ch;
			++ts;
			if(!delim)
			{
				ch=cpcio_getc_is(is);
			}
		}
	}
	char*t=realloc(tmp,ts+1);
	t[ts]=0;
	return t;
}

// change the delim used by the stream
// if any char in the str is found, the token is returned
// returns zero on success, fails if the delimiter array exceeds the maximum size
int cpcio_use_delim(struct cpcio____istream*is,const char*str)
{
	size_t len=strlen(str);
	if(len+1<CPCIO____MAX_DELIM_SIZE)
	{
		is->delimsz=len;
		strcpy(is->delim,str);
		return 0;
	}
	else
	{
		return-1;
	}
}

// get the delimiter
// the string will be null-terminated
const char*cpcio_get_delim(struct cpcio____istream*is)
{
	return is->delim;
}

// get an int
// token based
int cpcio_gint_is(struct cpcio____istream*is)
{
	char*t=cpcio_gtoken_is(is);
	int i=atoi(t);
	free(t);
	return i;
}

// gets a long
// token based
long cpcio_glong_is(struct cpcio____istream*is)
{
	char*t=cpcio_gtoken_is(is);
	long l=strtol(t,NULL,10);
	free(t);
	return l;
}

// gets a long long
// token based
long long cpcio_gll_is(struct cpcio____istream*is)
{
	char*t=cpcio_gtoken_is(is);
	long long ll=strtoll(t,NULL,10);
	free(t);
	return ll;
}

// gets an long long unsigned int
// token based
unsigned long long cpcio_gull_is(struct cpcio____istream*is)
{
	char*t=cpcio_gtoken_is(is);
	unsigned long long ull=strtoull(t,NULL,10);
	free(t);
	return ull;
}

// gets a float
// token based
float cpcio_gfloat_is(struct cpcio____istream*is)
{
	char*t=cpcio_gtoken_is(is);
	float f=strtof(t,NULL);
	free(t);
	return f;
}

// gets a double
// token based
double cpcio_gdouble_is(struct cpcio____istream*is)
{
	char*t=cpcio_gtoken_is(is);
	double d=strtod(t,NULL);
	free(t);
	return d;
}

// Returns true if there are currently more bytes waiting to be read.
int cpcio_istream_ready(struct cpcio____istream*is)
{
	return is->ready(is->src);
}

// default ready function, always returns false
int cpcio_default_ready(void*src)
{
	return 0;
}

// gets the source
// should only be used if making an istream
void*cpcio_src_is(struct cpcio____istream*is)
{
	return is->src;
}
#endif
#endif
