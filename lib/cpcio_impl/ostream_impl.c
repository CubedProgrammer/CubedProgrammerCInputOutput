#ifndef __cplusplus
#ifndef BUFSZ
#define BUFSZ 16384
#endif
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct __ostream
{
	char cbuf[BUFSZ];
	unsigned short bufs;
	FILE*f;
};
void cpcio_flush_os(struct __ostream*__os)
{
	fputs(__os->cbuf,__os->f);
	fflush(__os->f);
}
int closeos(struct __ostream*__os)
{
	return fclose(__os->f);
}
struct __ostream*openos(FILE*f)
{
	struct __ostream*__os=(struct __ostream*)malloc(sizeof(struct __ostream));
	__os->f=f;
	__os->bufs=0;
	for(char*__it__=__os->cbuf;__it__!=__os->cbuf+BUFSZ;++__it__)
	{
		*__it__=0;
	}
	return __os;
}
struct __ostream*openofs(const char*__fname)
{
	return openos(fopen(__fname,"w"));
}
struct __ostream*openofsa(const char*__fname)
{
	return openos(fopen(__fname,"a"));
}
void cpcio_putc_os(struct __ostream*__os,const char c)
{
	if(__os->bufs==BUFSZ)
	{
		cpcio_flush_os(__os);
		__os->bufs=0;
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
	char*str=(char*)malloc(12*sizeof(char));
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
	char*str=(char*)malloc(24*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%.17f\n",d);
	cpcio_puts_os(__os,str);
	free(str);
}
#endif
