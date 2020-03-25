#ifndef __cplusplus
#ifndef Included_fstream_h
#define Included_fstream_h
#include"istream.h"
#include"ostream.h"
struct __istream*openifs(const char*);
struct __ostream*openofs(const char*,const char*);
int __cpcio_read_ifs(void*,char*,size_t);
int __cpcio_write_ofs(void*,char*,size_t);
int __cpcio_close_fs(void*);
#endif
#endif
