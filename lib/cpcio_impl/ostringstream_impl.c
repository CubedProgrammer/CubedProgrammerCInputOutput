#ifndef __cplusplus
#ifndef BUFSZ
#define BUFSZ 16384
#endif
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct __ostringstream
{
	char cbuf[BUFSZ];
	unsigned short bufs;
	char*o;
	size_t ptr;
	size_t len;
};
void cpcio_flush_oss(struct __ostringstream*__oss)
{
	if(__oss->ptr+__oss->bufs>__oss->len)
	{
		__oss->o=(char*)realloc(__oss->o,__oss->ptr+__oss->bufs+3*BUFSZ);
	}
	strncpy(__oss->o+__oss->ptr,__oss->cbuf,__oss->bufs);
	__oss->ptr+=__oss->bufs;
	__oss->bufs=0;
}
int closeoss(struct __ostringstream*__oss)
{
	free(__oss->o);
	return 0;
}
struct __ostringstream*openoss(char*o)
{
	struct __ostringstream*__oss=(struct __ostringstream*)malloc(sizeof(struct __ostringstream));
	__oss->o=o;
	__oss->bufs=0;
	__oss->ptr=0;
	__oss->len=strlen(o);
	for(char*__it__=__oss->cbuf;__it__!=__oss->cbuf+BUFSZ;++__it__)
	{
		*__it__=0;
	}
	return __oss;
}
void cpcio_putc_oss(struct __ostringstream*__oss,const char c)
{
	if(__oss->bufs==BUFSZ)
	{
		cpcio_flush_oss(__oss);
	}
	__oss->cbuf[__oss->bufs]=c;
	++__oss->bufs;
}
void cpcio_puts_oss(struct __ostringstream*__oss,const char*str)
{
	size_t __l=strlen(str);
	for(size_t i=0;i<__l;i++)
	{
		cpcio_putc_oss(__oss,str[i]);
	}
}
void cpcio_putln_oss(struct __ostringstream*__oss,const char*str)
{
	cpcio_puts_oss(__oss,str);
	cpcio_putc_oss(__oss,'\n');
}
void cpcio_psqln_oss(struct __ostringstream*__oss,char**begin,char**end)
{
	while(begin!=end)
	{
		cpcio_puts_oss(__oss,*begin);
		++begin;
		if(begin==end)
		{
			cpcio_putc_oss(__oss,'\n');
		}
		else
		{
			cpcio_putc_oss(__oss,' ');
		}
	}
}
void cpcio_plnint_oss(struct __ostringstream*__oss,int i)
{
	char*str=(char*)malloc(12*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%d\n",i);
	cpcio_puts_oss(__oss,str);
	free(str);
}
void cpcio_plnl_oss(struct __ostringstream*__oss,long l)
{
	char*str=(char*)malloc(12*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%lli\n",l);
	cpcio_puts_oss(__oss,str);
	free(str);
}
void cpcio_plnll_oss(struct __ostringstream*__oss,long long ll)
{
	char*str=(char*)malloc(24*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%lli\n",ll);
	cpcio_puts_oss(__oss,str);
	free(str);
}
void cpcio_plnull_oss(struct __ostringstream*__oss,unsigned long long ull)
{
	char*str=(char*)malloc(24*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%llu\n",ull);
	cpcio_puts_oss(__oss,str);
	free(str);
}
void cpcio_plnf_oss(struct __ostringstream*__oss,float f)
{
	char*str=(char*)malloc(19*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%.8f\n",f);
	cpcio_puts_oss(__oss,str);
	free(str);
}
void cpcio_plnd_oss(struct __ostringstream*__oss,double d)
{
	char*str=(char*)malloc(37*sizeof(char));
	for(char*__it__=str;__it__!=str+12;++__it__)
	{
		*__it__=0;
	}
	sprintf(str,"%.17f\n",d);
	cpcio_puts_oss(__oss,str);
	free(str);
}
char*cpcio_str_oss(struct __ostringstream*__oss)
{
	char*str=(char*)malloc((__oss->ptr+1)*sizeof(char));
	strncpy(str,__oss->o,__oss->ptr);
	str[__oss->ptr]=0;
	return str;
}
#endif
