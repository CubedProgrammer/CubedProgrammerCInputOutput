#ifndef __cplusplus
#ifndef Included_header_only_cpcio_sstream_h
#define Included_header_only_cpcio_sstream_h
#include<stdlib.h>
#include<string.h>
#include<cpcio_istream.h>
#include<cpcio_ostream.h>
#include<cpcio_sstream.h>
#define CPCIO_OSS_SIZE 25001

// src for istringstream
// contains string and pointers
struct cpcio_iss_src
{
	const char*src;
	size_t ptr;
	size_t tot;
};

// src for ostringstream
// contains string and pointers
struct cpcio_oss_dest
{
	char*dest;
	size_t ptr;
	size_t tot;
};

// Test if there are more characters
int cpcio_iss_ready(void*src)
{
	struct cpcio_iss_src *s = src;
	return s->ptr < s->tot;
}

// opens an istringstream that reads from a string
// pass in a string and the istringstream will read from that
struct cpcio____istream*cpcio_open_isstream(const char*s)
{
	return cpcio_open_isstream_arr(s,strlen(s));
}

// opens an istringstream
// takes in an array instead of a null terminated string
struct cpcio____istream*cpcio_open_isstream_arr(const char*s,size_t sz)
{
	struct cpcio_iss_src*src=(struct cpcio_iss_src*)malloc(sizeof(struct cpcio_iss_src));
	src->src=s;
	src->ptr=0;
	src->tot=sz;
	struct cpcio____istream *is = cpcio_open_istream((void*)src,&cpcio_read_iss,&cpcio_close_iss);
	is->ready = &cpcio_iss_ready;
	return is;
}

// opens an ostringstream
// allows you to write to a string
struct cpcio____ostream*cpcio_open_osstream(void)
{
	struct cpcio_oss_dest*dest=(struct cpcio_oss_dest*)malloc(sizeof(struct cpcio_oss_dest));
	dest->ptr=0;
	dest->tot=CPCIO_OSS_SIZE;
	dest->dest=(char*)malloc(dest->tot*sizeof(char));
	dest->dest[dest->ptr]=0;
	return cpcio_open_ostream((void*)dest,&cpcio_write_oss,&cpcio_close_oss);
}

// get the string of the ostringstream
// will return the string that has been written to
char*cpcio_oss_str(struct cpcio____ostream*oss)
{
	cpcio_flush_os(oss);
	return((struct cpcio_oss_dest*)cpcio_dest_os(oss))->dest;
}

// read from istringstream
// given to istream's rd function pointer
int cpcio_read_iss(void*src_v_p,char*arr,size_t n)
{
	struct cpcio_iss_src*src=(struct cpcio_iss_src*)src_v_p;
	if(src->ptr<src->tot)
	{
		size_t i=src->ptr;
		for(char*__it__=arr;__it__!=arr+n&&i<src->tot;++__it__,i++)
		{
			*__it__=src->src[i];
		}
		size_t tmp=i;
		i-=src->ptr;
		src->ptr=tmp;
		return i;
	}
	else
	{
		return 0;
	}
}

// write to ostringstream
// given to ostream's rt function pointer
int cpcio_write_oss(void*src_v_p,const char*arr,size_t n)
{
	struct cpcio_oss_dest*src=(struct cpcio_oss_dest*)src_v_p;
	if(src->ptr+n>src->tot)
	{
		src->dest=realloc(src->dest,n>src->tot?src->tot*3+n:src->tot+n*3);
	}
	for(size_t i=0;i<n;i++,++src->ptr)
	{
		src->dest[src->ptr]=arr[i];
	}
	src->dest[src->ptr]=0;
	return n;
}

// close an istringstream
// given to the close function pointer
// doesn't really do anything
int cpcio_close_iss(void*src)
{return 0;}

// closes an ostringstream
// given to the close function pointer
int cpcio_close_oss(void*src_v_p)
{
	struct cpcio_oss_dest*src=(struct cpcio_oss_dest*)src_v_p;
	free(src->dest);
	return 0;
}
#endif
#endif
