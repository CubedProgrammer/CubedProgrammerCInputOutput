#ifndef __cplusplus
#ifndef Included_cpcio_fstream_h
#define Included_cpcio_fstream_h
#include<cpcio_istream.h>
#include<cpcio_ostream.h>
struct cpcio____istream*cpcio_open_ifstream(const char*);
struct cpcio____ostream*cpcio_open_ofstream(const char*,const char*);
size_t cpcio_read_ifs(void*,void*,size_t);
size_t cpcio_write_ofs(void*,const void*,size_t);
int cpcio_close_fs(void*);
#endif
#endif
