#ifndef __cplusplus
#ifndef Included_header_only_ostream_h
#define Included_header_only_ostream_h
#ifndef CPCIO____BUFSZ
#define CPCIO____BUFSZ 16384
#endif
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct cpcio____ostream;
void cpcio_flush_os(struct cpcio____ostream*);
int closeos(struct cpcio____ostream*);
struct cpcio____ostream*openos(void*,int(*)(void*,const char*,size_t),int(*)(void*));
void cpcio_putc_os(struct cpcio____ostream*,const char);
void cpcio_puts_os(struct cpcio____ostream*,const char*);
void cpcio_putln_os(struct cpcio____ostream*,const char*);
void cpcio_psqln_os(struct cpcio____ostream*,char**begin,char**end);
void cpcio_putint_os(struct cpcio____ostream*,int);
void cpcio_putl_os(struct cpcio____ostream*,long);
void cpcio_putll_os(struct cpcio____ostream*,long long);
void cpcio_putull_os(struct cpcio____ostream*,unsigned long long);
void cpcio_putf_os(struct cpcio____ostream*,float);
void cpcio_putd_os(struct cpcio____ostream*,double);
void cpcio_plnint_os(struct cpcio____ostream*,int);
void cpcio_plnl_os(struct cpcio____ostream*,long);
void cpcio_plnll_os(struct cpcio____ostream*,long long);
void cpcio_plnull_os(struct cpcio____ostream*,unsigned long long);
void cpcio_plnf_os(struct cpcio____ostream*,float);
void cpcio_plnd_os(struct cpcio____ostream*,double);
void*cpcio_dest_os(struct cpcio____ostream*);
typedef struct cpcio____ostream*ostream;

// ostream structure
// src is written to
// rt is the write function
// src is passed in, as well as a char buffer
// close is the close function that will be called on src
struct cpcio____ostream
{
	char cbuf[CPCIO____BUFSZ];
	unsigned short bufs;
	void*src;
	int(*rt)(void*,const char*,size_t);
	int(*close)(void*);
};

// flushes the ostream by calling rt on the char buf
// anything saved on the buffer is written out and cleared
void cpcio_flush_os(struct cpcio____ostream*__os)
{
	__os->rt(__os->src,__os->cbuf,__os->bufs);
	__os->bufs=0;
}

// closes the ostream
// the close function is called on src
int closeos(struct cpcio____ostream*__os)
{
	return __os->close(__os->src);
}

// opens an ostream
// should only be used if implementing a new type of ostream
// takes in the src pointer, rt, and close function pointers
struct cpcio____ostream*openos(void*__src,int(*__rtr)(void*,const char*,size_t),int(*__close)(void*))
{
	struct cpcio____ostream*__os=(struct cpcio____ostream*)malloc(sizeof(struct cpcio____ostream));
	__os->src=__src;
	__os->rt=__rtr;
	__os->close=__close;
	__os->bufs=0;
	for(char*__it__=__os->cbuf;__it__!=__os->cbuf+CPCIO____BUFSZ;++__it__)
	{
		*__it__=0;
	}
	return __os;
}

// puts a single character into the stream
// is written onto the buffer until full
void cpcio_putc_os(struct cpcio____ostream*__os,const char c)
{
	if(__os->bufs==CPCIO____BUFSZ)
	{
		cpcio_flush_os(__os);
	}
	__os->cbuf[__os->bufs]=c;
	++__os->bufs;
}

// writes a string to the stream
// the '\0' is not written
void cpcio_puts_os(struct cpcio____ostream*__os,const char*str)
{
	size_t __l=strlen(str);
	for(size_t i=0;i<__l;i++)
	{
		cpcio_putc_os(__os,str[i]);
	}
}

// writes as string followed by a line terminating char
// equivalent to cpcio_puts_os followed by putting '\n'
void cpcio_putln_os(struct cpcio____ostream*__os,const char*str)
{
	cpcio_puts_os(__os,str);
	cpcio_putc_os(__os,'\n');
}

// puts a sequence of strings into the stream
// puts a space between every string, and then a new line at the end
void cpcio_psqln_os(struct cpcio____ostream*__os,char**begin,char**end)
{
	while(begin!=end)
	{
		cpcio_puts_os(__os,*begin);
		++begin;
		if(begin==end)
		{
			cpcio_putc_os(__os,'\n');
		}
		else
		{
			cpcio_putc_os(__os,' ');
		}
	}
}

// puts an int into the stream
void cpcio_putint_os(struct cpcio____ostream*__os,int i)
{
	char*str=(char*)malloc(12*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%d",i);
	cpcio_puts_os(__os,str);
	free(str);
}

// puts a long into the stream
void cpcio_putl_os(struct cpcio____ostream*__os,long l)
{
	char*str=(char*)malloc(12*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%lli",l);
	cpcio_puts_os(__os,str);
	free(str);
}

// puts a long long into the stream
void cpcio_putll_os(struct cpcio____ostream*__os,long long ll)
{
	char*str=(char*)malloc(24*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%lli",ll);
	cpcio_puts_os(__os,str);
	free(str);
}

// puts a long long unsigned int into the stream
void cpcio_putull_os(struct cpcio____ostream*__os,unsigned long long ull)
{
	char*str=(char*)malloc(24*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%llu",ull);
	cpcio_puts_os(__os,str);
	free(str);
}

// puts a float into the stream
void cpcio_putf_os(struct cpcio____ostream*__os,float f)
{
	char*str=(char*)malloc(19*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%.8f",f);
	cpcio_puts_os(__os,str);
	free(str);
}

// puts a double into the stream
void cpcio_putd_os(struct cpcio____ostream*__os,double d)
{
	char*str=(char*)malloc(37*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%.17f",d);
	cpcio_puts_os(__os,str);
	free(str);
}

// puts an int on a new line
void cpcio_plnint_os(struct cpcio____ostream*__os,int i)
{
	char*str=(char*)malloc(12*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%d\n",i);
	cpcio_puts_os(__os,str);
	free(str);
}

// puts a long on a new line
void cpcio_plnl_os(struct cpcio____ostream*__os,long l)
{
	char*str=(char*)malloc(12*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%lli\n",l);
	cpcio_puts_os(__os,str);
	free(str);
}

// puts a long long on a new line
void cpcio_plnll_os(struct cpcio____ostream*__os,long long ll)
{
	char*str=(char*)malloc(24*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%lli\n",ll);
	cpcio_puts_os(__os,str);
	free(str);
}

// puts a long long unsigned int on a new line
void cpcio_plnull_os(struct cpcio____ostream*__os,unsigned long long ull)
{
	char*str=(char*)malloc(24*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%llu\n",ull);
	cpcio_puts_os(__os,str);
	free(str);
}

// puts a float on a new line
void cpcio_plnf_os(struct cpcio____ostream*__os,float f)
{
	char*str=(char*)malloc(19*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%.8f\n",f);
	cpcio_puts_os(__os,str);
	free(str);
}

// puts a double on a new line
void cpcio_plnd_os(struct cpcio____ostream*__os,double d)
{
	char*str=(char*)malloc(37*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%.17f\n",d);
	cpcio_puts_os(__os,str);
	free(str);
}

// gets the destination of the stream
// should only be used if implementing a new type of ostream
void*cpcio_dest_os(struct cpcio____ostream*__os)
{
	return __os->src;
}
#endif
#endif
