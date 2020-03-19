#ifndef __cplusplus
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
struct __istream
{
	char cbuf[BUFSZ];
	unsigned short bufs;
	FILE*f;
	char delim[MAX_DELIM_SIZE];
	unsigned short delimsz;
};
int closeis(struct __istream*__is)
{
	return fclose(__is->f);
}
struct __istream*openis(FILE*__f)
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
	__is->f=__f;
	__is->bufs=BUFSZ;
	__is->delimsz=3;
	return __is;
}
struct __istream*openifs(const char*__fname)
{
	return openis(fopen(__fname,"r"));
}
char cpcio_getc_is(struct __istream*__is)
{
	if(__is->bufs<BUFSZ)
	{
		char c=__is->cbuf[__is->bufs];
		++__is->bufs;
		return c;
	}
	else
	{
		fgets(__is->cbuf,BUFSZ,__is->f);
		__is->bufs=1;
		return*__is->cbuf;
	}
}
char*cpcio_gtoken_is(struct __istream*__is)
{
	char __ch=cpcio_getc_is(__is);
	bool delim=false;
	char*__tmp=(char*)malloc(BUFSZ*sizeof(char));
	size_t __as=BUFSZ;
	size_t __ts=0;
	for(size_t i=0;i<__is->delimsz;i++)
	{
		if(__is->delim[i]==__ch)
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
			if(__is->delim[i]==__ch)
			{
				delim=true;
			}
		}
	}
	char*__t=realloc(__tmp,__ts+1);
	__t[__ts]=0;
	return __t;
}
void cpcio_use_delim(struct __istream*__is,const char*str)
{
	__is->delimsz=strlen(str);
	strcpy(__is->delim,str);
}
char*cpcio_get_delim(struct __istream*__is)
{
	char*delim=(char*)malloc(__is->delimsz*sizeof(char));
	strncpy(delim,__is->delim,__is->delimsz);
	return delim;
}
int cpcio_gint_is(struct __istream*__is)
{
	char*__t=cpcio_gtoken_is(__is);
	int i=atoi(__t);
	free(__t);
	return i;
}
long cpcio_glong_is(struct __istream*__is)
{
	char*__t=cpcio_gtoken_is(__is);
	long l=strtol(__t,NULL,10);
	free(__t);
	return l;
}
long long cpcio_gll_is(struct __istream*__is)
{
	char*__t=cpcio_gtoken_is(__is);
	long long ll=strtoll(__t,NULL,10);
	free(__t);
	return ll;
}
unsigned long long cpcio_gull_is(struct __istream*__is)
{
	char*__t=cpcio_gtoken_is(__is);
	unsigned long long ull=strtoull(__t,NULL,10);
	free(__t);
	return ull;
}
float cpcio_gfloat_is(struct __istream*__is)
{
	char*__t=cpcio_gtoken_is(__is);
	float f=strtof(__t,NULL);
	free(__t);
	return f;
}
double cpcio_gdouble_is(struct __istream*__is)
{
	char*__t=cpcio_gtoken_is(__is);
	double d=strtod(__t,NULL);
	free(__t);
	return d;
}
#endif
