#ifndef __cplusplus
#ifndef Included_header_only_ostream_h
#define Included_header_only_ostream_h
#ifndef BUFSZ
#define BUFSZ 16384
#endif
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct __ostream;
void cpcio_flush_os(struct __ostream*);
int closeos(struct __ostream*);
struct __ostream*openos(void*,int(*)(void*,const char*,size_t),int(*)(void*));
void cpcio_putc_os(struct __ostream*,const char);
void cpcio_puts_os(struct __ostream*,const char*);
void cpcio_putln_os(struct __ostream*,const char*);
void cpcio_psqln_os(struct __ostream*,char**begin,char**end);
void cpcio_plnint_os(struct __ostream*,int);
void cpcio_plnl_os(struct __ostream*,long);
void cpcio_plnll_os(struct __ostream*,long long);
void cpcio_plnull_os(struct __ostream*,unsigned long long);
void cpcio_plnf_os(struct __ostream*,float);
void cpcio_plnd_os(struct __ostream*,double);
void*cpcio_dest_os(struct __ostream*);
typedef struct __ostream*ostream;
struct __ostream
{
	char cbuf[BUFSZ];
	unsigned short bufs;
	void*src;
	int(*rt)(void*,const char*,size_t);
	int(*close)(void*);
};
void cpcio_flush_os(struct __ostream*__os)
{
	__os->rt(__os->src,__os->cbuf,__os->bufs);
	__os->bufs=0;
}
int closeos(struct __ostream*__os)
{
	return __os->close(__os->src);
}
struct __ostream*openos(void*__src,int(*__rtr)(void*,const char*,size_t),int(*__close)(void*))
{
	struct __ostream*__os=(struct __ostream*)malloc(sizeof(struct __ostream));
	__os->src=__src;
	__os->rt=__rtr;
	__os->close=__close;
	__os->bufs=0;
	for(char*__it__=__os->cbuf;__it__!=__os->cbuf+BUFSZ;++__it__)
	{
		*__it__=0;
	}
	return __os;
}
void cpcio_putc_os(struct __ostream*__os,const char c)
{
	if(__os->bufs==BUFSZ)
	{
		cpcio_flush_os(__os);
	}
	__os->cbuf[__os->bufs]=c;
	++__os->bufs;
}
void cpcio_puts_os(struct __ostream*__os,const char*str)
{
	size_t __l=strlen(str);
	for(size_t i=0;i<__l;i++)
	{
		cpcio_putc_os(__os,str[i]);
	}
}
void cpcio_putln_os(struct __ostream*__os,const char*str)
{
	cpcio_puts_os(__os,str);
	cpcio_putc_os(__os,'\n');
}
void cpcio_psqln_os(struct __ostream*__os,char**begin,char**end)
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
void cpcio_plnint_os(struct __ostream*__os,int i)
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
void cpcio_plnl_os(struct __ostream*__os,long l)
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
void cpcio_plnll_os(struct __ostream*__os,long long ll)
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
void cpcio_plnull_os(struct __ostream*__os,unsigned long long ull)
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
void cpcio_plnf_os(struct __ostream*__os,float f)
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
void cpcio_plnd_os(struct __ostream*__os,double d)
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
void*cpcio_dest_os(struct __ostream*__os)
{
	return __os->src;
}
#endif
#endif
