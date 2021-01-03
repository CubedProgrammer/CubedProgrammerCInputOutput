#ifndef __cplusplus
#ifndef Included_sstream_h
#define Included_sstream_h
#include"istream.h"
#include"ostream.h"
struct __isssrc;
struct __ossdest;
struct __istream*openiss(const char*);
struct __ostream*openoss(void);
char*cpcio_oss_str(struct __ostream*);
int __cpcio_read_iss(void*,char*,size_t);
int __cpcio_write_oss(void*,const char*,size_t);
int __cpcio_close_iss(void*);
int __cpcio_close_oss(void*);
#endif
#endif
