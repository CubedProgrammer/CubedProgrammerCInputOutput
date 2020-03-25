#ifndef __cplusplus
#include<stdlib.h>
#include<string.h>
#include<lib/sstream.h>
#define __CPCIO_OSS_SIZE 25001
struct __isssrc
{
	const char*src;
	size_t ptr;
	size_t tot;
};
struct __ossdest
{
	char*dest;
	size_t ptr;
	size_t tot;
};
struct __istream*openiss(const char*__s)
{
	struct __isssrc*__src=(struct __isssrc*)malloc(sizeof(struct __isssrc));
	__src->src=__s;
	__src->ptr=0;
	__src->tot=strlen(__s);
	return openis((void*)__src,&__cpcio_read_iss,&__cpcio_close_iss);
}
struct __ostream*openoss()
{
	struct __ossdest*__dest=(struct __ossdest*)malloc(sizeof(struct __ossdest));
	__dest->ptr=0;
	__dest->tot=__CPCIO_OSS_SIZE;
	__dest->dest=(char*)malloc(__dest->tot*sizeof(char));
	__dest->dest[__dest->ptr]=0;
	return openos((void*)__dest,&__cpcio_write_oss,&__cpcio_close_oss);
}
int __cpcio_read_iss(void*__src_v_p,char*__arr,size_t __n)
{
	struct __isssrc*__src=(struct __isssrc*)__src_v_p;
	if(__src->ptr<__src->tot)
	{
		size_t i=__src->ptr;
		for(char*__it__=__arr;__it__!=__arr+__n&&i<__src->tot;i++)
		{
			*__it__=__src->src[i];
		}
		size_t tmp=i;
		i-=__src->ptr;
		__src->ptr=tmp;
		return i;
	}
	else
	{
		return 0;
	}
}
int __cpcio_write_oss(void*__src_v_p,const char*__arr,size_t __n)
{
	struct __ossdest*__src=(struct __ossdest*)__src_v_p;
	if(__src->ptr+__n>__src->tot)
	{
		__src->dest=realloc(__src->dest,__n>__src->tot?__src->tot*3+__n:__src->tot+__n*3);
	}
	for(size_t i=0;i<__n;i++,++__src->ptr)
	{
		__src->dest[__src->ptr]=__arr[i];
	}
	__src->dest[__src->ptr]=0;
	return __n;
}
int __cpcio_close_iss(void*__src)
{return 0;}
int __cpcio_close_oss(void*__src_v_p)
{
	struct __ossdest*__src=(struct __ossdest*)__src_v_p;
	free(__src->dest);
	return 0;
}
#endif
