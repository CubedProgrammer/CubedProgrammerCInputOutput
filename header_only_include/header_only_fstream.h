#ifndef __cplusplus
#ifndef Included_header_only_fstream_h
#define Included_header_only_fstream_h
#include<stdio.h>
#include<string.h>
#include<istream.h>
#include<ostream.h>
#ifndef BUFSZ
#define BUFSZ 16384
#endif
struct __istream*openifs(const char*);
struct __ostream*openofs(const char*,const char*);
int __cpcio_read_ifs(void*,char*,size_t);
int __cpcio_write_ofs(void*,const char*,size_t);
int __cpcio_close_fs(void*);

// opens an ifstream to read a file
// pass in the name of the file
struct __istream*openifs(const char*__fname)
{
	return openis((void*)fopen(__fname,"r"),&__cpcio_read_ifs,&__cpcio_close_fs);
}

// opens an ofstream to write to a file
// pass in the file name and the mode
// mode can be w or a, returns NULL on invalid mode
struct __ostream*openofs(const char*__fname,const char*__m)
{
	if(strcmp(__m,"w")==0||strcmp(__m,"a")==0)
	{
		return openos((void*)fopen(__fname,__m),&__cpcio_write_ofs,&__cpcio_close_fs);
	}
	else
	{
		return NULL;
	}
}

// function for reading from ifstream src
// given to istream's rd function pointer
int __cpcio_read_ifs(void*__src,char*__arr,size_t __n)
{
	size_t __t=fread(__arr,sizeof(char),__n,(FILE*)__src);
	if(__t<BUFSZ)
		memset(__arr+__t,-1,BUFSZ-__t);
	return __t==0?0:1;
}

// function for writing to ofstream dest
// given to ostream's rt function pointer
int __cpcio_write_ofs(void*__src,const char*__arr,size_t __n)
{
	return fwrite(__arr,sizeof(char),__n,(FILE*)__src);
}

// function for closing both streams
// used for both ifstream and ofstream
int __cpcio_close_fs(void*__src)
{
	return fclose((FILE*)__src);
}
#endif
#endif
