#ifndef __cplusplus
#ifndef Included_header_only_istream_h
#define Included_header_only_istream_h
#ifndef BUFSZ
#define BUFSZ 16384
#endif
#ifndef MAX_DELIM_SIZE
#define MAX_DELIM_SIZE 100
#endif
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct __istream;
int closeis(struct __istream*);
struct __istream*openis(void*,int(*)(void*,char*,size_t),int(*)(void*));
char cpcio_getc_is(struct __istream*);
char*cpcio_gtoken_is(struct __istream*);
void cpcio_use_delim(struct __istream*,const char*);
char*cpcio_get_delim(struct __istream*);
int cpcio_gint_is(struct __istream*);
long cpcio_glong_is(struct __istream*);
long long cpcio_gll_is(struct __istream*);
unsigned long long cpcio_gull_is(struct __istream*);
float cpcio_gfloat_is(struct __istream*);
double cpcio_gdouble_is(struct __istream*);
void*cpcio_src_is(struct __istream*);
typedef struct __istream*istream;

// the istream structure
// src is the thing that is read from
// rd is for reading, the src is passed in
// and it must read chars into the buffer
// close function is called when the stream is closed
struct __istream
{
	void*src;
	int(*rd)(void*,char*,size_t);
	int(*close)(void*);
	bool eof;
	char cbuf[BUFSZ];
	unsigned short bufs;
	char delim[MAX_DELIM_SIZE];
	unsigned short delimsz;
};

// closes the istream
int closeis(struct __istream*__is)
{
	return __is->close(__is->src);
}

// opens an istream given src
// and pointers to required functions
struct __istream*openis(void*__src,int(*__rdr)(void*,char*,size_t),int(*__close)(void*))
{
	struct __istream*__is=(struct __istream*)malloc(sizeof(struct __istream));
	for(char*__it__=__is->cbuf;__it__!=__is->cbuf+BUFSZ;++__it__)
	{
		*__it__=0;
	}
	for(char*__it__=__is->delim;__it__!=__is->delim+MAX_DELIM_SIZE;++__it__)
	{
		*__it__=0;
	}
	strcpy(__is->delim,"\n\t ");
	__is->src=__src;
	__is->rd=__rdr;
	__is->close=__close;
	__is->eof=false;
	__is->bufs=BUFSZ;
	__is->delimsz=3;
	return __is;
}

// gets one character
// or 0xff is eof is reached
char cpcio_getc_is(struct __istream*__is)
{
	if(__is->eof)
	{
		return 0xff;
	}
	else if(__is->bufs<BUFSZ)
	{
		char c=__is->cbuf[__is->bufs];
		++__is->bufs;
		return c;
	}
	else
	{
		int __c=__is->rd(__is->src,__is->cbuf,BUFSZ);
		__is->bufs=1;
		if(__c==0)
		{
			__is->bufs=0;
			__is->eof=true;
		}
		return __c==0?-1:*__is->cbuf;
	}
}

// reads a token based on delimiters
// returns it as a heap allocated char array
char*cpcio_gtoken_is(struct __istream*__is)
{
	char __ch=cpcio_getc_is(__is);
	bool delim=false;
	char*__tmp=(char*)malloc(BUFSZ*sizeof(char));
	size_t __as=BUFSZ;
	size_t __ts=0;
	for(size_t i=0;i<__is->delimsz;i++)
	{
		if(__ch==-1||__is->delim[i]==__ch)
		{
			delim=true;
		}
	}
	while(!delim)
	{
		if(__ts==__as)
		{
			__tmp=realloc(__tmp,__as+BUFSZ);
		}
		__tmp[__ts]=__ch;
		++__ts;
		__ch=cpcio_getc_is(__is);
		delim=false;
		for(size_t i=0;i<__is->delimsz;i++)
		{
			if(__ch==-1||__is->delim[i]==__ch)
			{
				delim=true;
			}
		}
	}
	char*__t=realloc(__tmp,__ts+1);
	__t[__ts]=0;
	return __t;
}

// change the delim used by the stream
// if any char in the str is found, the token is returned
void cpcio_use_delim(struct __istream*__is,const char*str)
{
	__is->delimsz=strlen(str);
	strcpy(__is->delim,str);
}

// get the delimiter
// the string returned is allocated with malloc
// and is a copy of the delimiter
// changing it won't affect anything
char*cpcio_get_delim(struct __istream*__is)
{
	char*delim=(char*)malloc(__is->delimsz*sizeof(char));
	strncpy(delim,__is->delim,__is->delimsz);
	return delim;
}

// get an int
// token based
int cpcio_gint_is(struct __istream*__is)
{
	char*__t=cpcio_gtoken_is(__is);
	int i=atoi(__t);
	free(__t);
	return i;
}

// gets a long
// token based
long cpcio_glong_is(struct __istream*__is)
{
	char*__t=cpcio_gtoken_is(__is);
	long l=strtol(__t,NULL,10);
	free(__t);
	return l;
}

// gets a long long
// token based
long long cpcio_gll_is(struct __istream*__is)
{
	char*__t=cpcio_gtoken_is(__is);
	long long ll=strtoll(__t,NULL,10);
	free(__t);
	return ll;
}

// gets an long long unsigned int
// token based
unsigned long long cpcio_gull_is(struct __istream*__is)
{
	char*__t=cpcio_gtoken_is(__is);
	unsigned long long ull=strtoull(__t,NULL,10);
	free(__t);
	return ull;
}

// gets a float
// token based
float cpcio_gfloat_is(struct __istream*__is)
{
	char*__t=cpcio_gtoken_is(__is);
	float f=strtof(__t,NULL);
	free(__t);
	return f;
}

// gets a double
// token based
double cpcio_gdouble_is(struct __istream*__is)
{
	char*__t=cpcio_gtoken_is(__is);
	double d=strtod(__t,NULL);
	free(__t);
	return d;
}

// gets the source
// should only be used if making an istream
void*cpcio_src_is(struct __istream*__is)
{
	return __is->src;
}
#endif
#endif
