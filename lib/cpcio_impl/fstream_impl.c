#ifndef __cplusplus
#include<stdio.h>
#include<string.h>
#include<fstream.h>
struct __istream*openifs(const char*__fname)
{
	return openis((void*)fopen(__fname,"r"),&__cpcio_read_ifs,&__cpcio_close_fs);
}
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
int __cpcio_read_ifs(void*__src,char*__arr,size_t __n)
{
	char*__t=fgets(__arr,__n,(FILE*)__src);
	return __t==NULL?0:1;
}
int __cpcio_write_ofs(void*__src,const char*__arr,size_t __n)
{
	return fwrite(__arr,sizeof(char),__n,(FILE*)__src);
}
int __cpcio_close_fs(void*__src)
{
	return fclose((FILE*)__src);
}
#endif
