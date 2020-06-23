#ifndef __cplusplus
#ifndef Included_header_only_sstream_h
#define Included_header_only_sstream_h
#include<stdlib.h>
#include<string.h>
#include<istream.h>
#include<ostream.h>
#define __CPCIO_OSS_SIZE 25001
struct __isssrc;
struct __ossdest;
struct __istream*openiss(const char*);
struct __ostream*openoss(void);
char*cpcio_oss_str(struct __ostream*);
int __cpcio_read_iss(void*,char*,size_t);
int __cpcio_write_oss(void*,const char*,size_t);
int __cpcio_close_iss(void*);
int __cpcio_close_oss(void*);

// src for istringstream
// contains string and pointers
struct __isssrc
{
	const char*src;
	size_t ptr;
	size_t tot;
};

// src for ostringstream
// contains string and pointers
struct __ossdest
{
	char*dest;
	size_t ptr;
	size_t tot;
};

// opens an istringstream that reads from a string
// pass in a string and the istringstream will read from that
struct __istream*openiss(const char*__s)
{
	struct __isssrc*__src=(struct __isssrc*)malloc(sizeof(struct __isssrc));
	__src->src=__s;
	__src->ptr=0;
	__src->tot=strlen(__s);
	return openis((void*)__src,&__cpcio_read_iss,&__cpcio_close_iss);
}

// opens an ostringstream
// allows you to write to a string
struct __ostream*openoss(void)
{
	struct __ossdest*__dest=(struct __ossdest*)malloc(sizeof(struct __ossdest));
	__dest->ptr=0;
	__dest->tot=__CPCIO_OSS_SIZE;
	__dest->dest=(char*)malloc(__dest->tot*sizeof(char));
	__dest->dest[__dest->ptr]=0;
	return openos((void*)__dest,&__cpcio_write_oss,&__cpcio_close_oss);
}

// get the string of the ostringstream
// will return the string that has been written to
char*cpcio_oss_str(struct __ostream*__oss)
{
	cpcio_flush_os(__oss);
	return((struct __ossdest*)cpcio_dest_os(__oss))->dest;
}

// read from istringstream
// given to istream's rd function pointer
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

// write to ostringstream
// given to ostream's rt function pointer
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

// close an istringstream
// given to the close function pointer
// doesn't really do anything
int __cpcio_close_iss(void*__src)
{return 0;}

// closes an ostringstream
// given to the close function pointer
int __cpcio_close_oss(void*__src_v_p)
{
	struct __ossdest*__src=(struct __ossdest*)__src_v_p;
	free(__src->dest);
	return 0;
}
#endif
#endif
