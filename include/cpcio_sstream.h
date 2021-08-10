#ifndef __cplusplus
#ifndef Included_cpcio_sstream_h
#define Included_cpcio_sstream_h
#include<cpcio_istream.h>
#include<cpcio_ostream.h>
struct cpcio_iss_src;
struct cpcio_oss_dest;
struct cpcio____istream*cpcio_open_isstream(const char*);
struct cpcio____ostream*cpcio_open_osstream(void);
char*cpcio_oss_str(struct cpcio____ostream*);
int cpcio_read_iss(void*,char*,size_t);
int cpcio_write_oss(void*,const char*,size_t);
int cpcio_close_iss(void*);
int cpcio_close_oss(void*);
#endif
#endif
