#ifndef __cplusplus
#ifndef Included_sstream_h
#define Included_sstream_h
#include"istream.h"
#include"ostream.h"
struct cpcio_iss_src;
struct cpcio_oss_dest;
struct cpcio____istream*openiss(const char*);
struct cpcio____ostream*openoss(void);
char*cpcio_oss_str(struct cpcio____ostream*);
int cpcio_read_iss(void*,char*,size_t);
int cpcio_write_oss(void*,const char*,size_t);
int cpcio_close_iss(void*);
int cpcio_close_oss(void*);
#endif
#endif
