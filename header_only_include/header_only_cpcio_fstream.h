#ifndef __cplusplus
#ifndef Included_header_only_cpcio_fstream_h
#define Included_header_only_cpcio_fstream_h
#include<stdio.h>
#include<string.h>
#include<cpcio_istream.h>
#include<cpcio_ostream.h>
#ifndef CPCIO____BUFSZ
#define CPCIO____BUFSZ 16384
#endif
struct cpcio____istream*cpcio_open_ifstream(const char*);
struct cpcio____ostream*cpcio_open_ofstream(const char*,const char*);
int cpcio_read_ifs(void*,char*,size_t);
int cpcio_write_ofs(void*,const char*,size_t);
int cpcio_close_fs(void*);

// opens an ifstream to read a file
// pass in the name of the file
struct cpcio____istream*cpcio_open_ifstream(const char*fname)
{
	FILE *fhand = fopen(fname,"r");
	setvbuf(fhand, NULL, _IONBF, 0);
	return cpcio_open_istream((void*)fhand,&cpcio_read_ifs,&cpcio_close_fs);
}

// opens an ofstream to write to a file
// pass in the file name and the mode
// mode can be w or a, returns NULL on invalid mode
struct cpcio____ostream*cpcio_open_ofstream(const char*fname,const char*m)
{
	if(strcmp(m,"w")==0||strcmp(m,"a")==0)
	{
		FILE *fhand = fopen(fname,m);
		setvbuf(fhand, NULL, _IONBF, 0);
		return cpcio_open_ostream((void*)fhand,&cpcio_write_ofs,&cpcio_close_fs);
	}
	else
	{
		return NULL;
	}
}

// function for reading from ifstream src
// given to istream's rd function pointer
int cpcio_read_ifs(void*src,char*arr,size_t n)
{
	size_t t=fread(arr,sizeof(char),n,(FILE*)src);
	if(t<CPCIO____BUFSZ)
		memset(arr+t,-1,CPCIO____BUFSZ-t);
	return t;
}

// function for writing to ofstream dest
// given to ostream's rt function pointer
int cpcio_write_ofs(void*src,const char*arr,size_t n)
{
	return fwrite(arr,sizeof(char),n,(FILE*)src);
}

// function for closing both streams
// used for both ifstream and ofstream
int cpcio_close_fs(void*src)
{
	return fclose((FILE*)src);
}
#endif
#endif
