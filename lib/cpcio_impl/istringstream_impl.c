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
struct __istringstream
{
	char*str;
	size_t ptr;
	size_t len;
	char cbuf[BUFSZ];
	unsigned short bufs;
	char delim[MAX_DELIM_SIZE];
	unsigned short delimsz;
};
struct __istringstream*openiss(const char*str)
{
	struct __istringstream*__iss=(struct __istringstream*)malloc(sizeof(struct __istringstream));
	size_t len=strlen(str)+1;
	__iss->str=(char*)malloc(len*sizeof(char));
	__iss->bufs=BUFSZ;
	strcpy(__iss->str,str);
	for(char*__it__=__iss->cbuf;__it__!=__iss->cbuf+BUFSZ;++__it__)
	{
		*__it__=0;
	}
	for(char*__it__=__iss->delim;__it__!=__iss->delim+MAX_DELIM_SIZE;++__it__)
	{
		*__it__=0;
	}
	strcpy(__iss->delim,"\n\t ");
	__iss->delimsz=3;
	__iss->ptr=0;
	return __iss;
}
char cpcio_getc_iss(struct __istringstream*__iss)
{
	if(__iss->bufs<BUFSZ)
	{
		char c=__iss->cbuf[__iss->bufs];
		++__iss->bufs;
		return c;
	}
	else
	{
		strncpy(__iss->cbuf,__iss->str,BUFSZ);
		if(__iss->ptr+BUFSZ>=__iss->len)
		{
			__iss->ptr=__iss->len;
			free(__iss->str);
		}
		else
		{
			__iss->ptr+=BUFSZ;
		}
		__iss->bufs=1;
		return*__iss->cbuf;
	}
}
char*cpcio_gtoken_iss(struct __istringstream*__iss)
{
	char __ch=cpcio_getc_iss(__iss);
	bool delim=false;
	char*__tmp=(char*)malloc(BUFSZ*sizeof(char));
	size_t __as=BUFSZ;
	size_t __ts=0;
	for(size_t i=0;i<__iss->delimsz;i++)
	{
		if(__iss->delim[i]==__ch)
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
		__ch=cpcio_getc_iss(__iss);
		delim=false;
		for(size_t i=0;i<__iss->delimsz;i++)
		{
			if(__iss->delim[i]==__ch)
			{
				delim=true;
			}
		}
	}
	char*__t=realloc(__tmp,__ts+1);
	__t[__ts]=0;
	return __t;
}
void cpcio_udelim_iss(struct __istringstream*__iss,const char*str)
{
	__iss->delimsz=strlen(str);
	strcpy(__iss->delim,str);
}
char*cpcio_gdelim_iss(struct __istringstream*__iss)
{
	char*delim=(char*)malloc(__iss->delimsz*sizeof(char));
	strncpy(delim,__iss->delim,__iss->delimsz);
	return delim;
}
int cpcio_gint_iss(struct __istringstream*__iss)
{
	char*__t=cpcio_gtoken_iss(__iss);
	int i=atoi(__t);
	free(__t);
	return i;
}
long cpcio_glong_iss(struct __istringstream*__iss)
{
	char*__t=cpcio_gtoken_iss(__iss);
	long l=strtol(__t,NULL,10);
	free(__t);
	return l;
}
long long cpcio_gll_iss(struct __istringstream*__iss)
{
	char*__t=cpcio_gtoken_iss(__iss);
	long long ll=strtoll(__t,NULL,10);
	free(__t);
	return ll;
}
unsigned long long cpcio_gull_iss(struct __istringstream*__iss)
{
	char*__t=cpcio_gtoken_iss(__iss);
	unsigned long long ull=strtoull(__t,NULL,10);
	free(__t);
	return ull;
}
float cpcio_gfloat_iss(struct __istringstream*__iss)
{
	char*__t=cpcio_gtoken_iss(__iss);
	float f=strtof(__t,NULL);
	free(__t);
	return f;
}
double cpcio_gdouble_iss(struct __istringstream*__iss)
{
	char*__t=cpcio_gtoken_iss(__iss);
	double d=strtod(__t,NULL);
	free(__t);
	return d;
}
#endif
