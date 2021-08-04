#ifndef __cplusplus
#ifndef Included_header_only_ostream_h
#define Included_header_only_ostream_h
#ifndef CPCIO____BUFSZ
#define CPCIO____BUFSZ 16384
#endif
#include<string.h>
#include<ostream.h>

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
void cpcio_flush_os(struct cpcio____ostream*os)
{
	os->rt(os->src,os->cbuf,os->bufs);
	os->bufs=0;
}

// closes the ostream
// the close function is called on src
int cpcio_close_ostream(struct cpcio____ostream*os)
{
	return os->close(os->src);
}

// opens an ostream
// should only be used if implementing a new type of ostream
// takes in the src pointer, rt, and close function pointers
struct cpcio____ostream*cpcio_open_ostream(void*src,int(*rtr)(void*,const char*,size_t),int(*close)(void*))
{
	struct cpcio____ostream*os=(struct cpcio____ostream*)malloc(sizeof(struct cpcio____ostream));
	os->src=src;
	os->rt=rtr;
	os->close=close;
	os->bufs=0;
	for(char*__it__=os->cbuf;__it__!=os->cbuf+CPCIO____BUFSZ;++__it__)
	{
		*__it__=0;
	}
	return os;
}

// writes a block of data
// returns number of bytes written
size_t cpcio_wr(struct cpcio____ostream*os,const void*buf,size_t sz)
{
	return os->rt(os->src,buf,sz);
}

// puts a single character into the stream
// is written onto the buffer until full
void cpcio_putc_os(struct cpcio____ostream*os,const char c)
{
	if(os->bufs==CPCIO____BUFSZ)
	{
		cpcio_flush_os(os);
	}
	os->cbuf[os->bufs]=c;
	++os->bufs;
}

// writes a string to the stream
// the '\0' is not written
void cpcio_puts_os(struct cpcio____ostream*os,const char*str)
{
	size_t l=strlen(str);
	for(size_t i=0;i<l;i++)
	{
		cpcio_putc_os(os,str[i]);
	}
}

// writes as string followed by a line terminating char
// equivalent to cpcio_puts_os followed by putting '\n'
void cpcio_putln_os(struct cpcio____ostream*os,const char*str)
{
	cpcio_puts_os(os,str);
	cpcio_putc_os(os,'\n');
}

// puts a sequence of strings into the stream
// puts a space between every string, and then a new line at the end
void cpcio_psqln_os(struct cpcio____ostream*os,char**begin,char**end)
{
	while(begin!=end)
	{
		cpcio_puts_os(os,*begin);
		++begin;
		if(begin==end)
		{
			cpcio_putc_os(os,'\n');
		}
		else
		{
			cpcio_putc_os(os,' ');
		}
	}
}

// puts an int into the stream
void cpcio_putint_os(struct cpcio____ostream*os,int i)
{
	char*str=(char*)malloc(12*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%d",i);
	cpcio_puts_os(os,str);
	free(str);
}

// puts a long into the stream
void cpcio_putl_os(struct cpcio____ostream*os,long l)
{
	char*str=(char*)malloc(12*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%li",l);
	cpcio_puts_os(os,str);
	free(str);
}

// puts a long long into the stream
void cpcio_putll_os(struct cpcio____ostream*os,long long ll)
{
	char*str=(char*)malloc(24*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%lli",ll);
	cpcio_puts_os(os,str);
	free(str);
}

// puts a long long unsigned int into the stream
void cpcio_putull_os(struct cpcio____ostream*os,unsigned long long ull)
{
	char*str=(char*)malloc(24*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%llu",ull);
	cpcio_puts_os(os,str);
	free(str);
}

// puts a float into the stream
void cpcio_putf_os(struct cpcio____ostream*os,float f)
{
	char*str=(char*)malloc(19*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%.8f",f);
	cpcio_puts_os(os,str);
	free(str);
}

// puts a double into the stream
void cpcio_putd_os(struct cpcio____ostream*os,double d)
{
	char*str=(char*)malloc(37*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%.17f",d);
	cpcio_puts_os(os,str);
	free(str);
}

// puts an int on a new line
void cpcio_plnint_os(struct cpcio____ostream*os,int i)
{
	char*str=(char*)malloc(12*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%d\n",i);
	cpcio_puts_os(os,str);
	free(str);
}

// puts a long on a new line
void cpcio_plnl_os(struct cpcio____ostream*os,long l)
{
	char*str=(char*)malloc(12*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%li\n",l);
	cpcio_puts_os(os,str);
	free(str);
}

// puts a long long on a new line
void cpcio_plnll_os(struct cpcio____ostream*os,long long ll)
{
	char*str=(char*)malloc(24*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%lli\n",ll);
	cpcio_puts_os(os,str);
	free(str);
}

// puts a long long unsigned int on a new line
void cpcio_plnull_os(struct cpcio____ostream*os,unsigned long long ull)
{
	char*str=(char*)malloc(24*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%llu\n",ull);
	cpcio_puts_os(os,str);
	free(str);
}

// puts a float on a new line
void cpcio_plnf_os(struct cpcio____ostream*os,float f)
{
	char*str=(char*)malloc(19*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%.8f\n",f);
	cpcio_puts_os(os,str);
	free(str);
}

// puts a double on a new line
void cpcio_plnd_os(struct cpcio____ostream*os,double d)
{
	char*str=(char*)malloc(37*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%.17f\n",d);
	cpcio_puts_os(os,str);
	free(str);
}

// gets the destination of the stream
// should only be used if implementing a new type of ostream
void*cpcio_dest_os(struct cpcio____ostream*os)
{
	return os->src;
}
#endif
#endif
