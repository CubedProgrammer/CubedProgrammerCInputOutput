#ifndef __cplusplus
#ifndef Included_istream_h
#define Included_istream_h
#include<stdio.h>
struct __istream;
int closeis(struct __istream*);
struct __istream*openis(FILE*);
struct __istream*openifs(const char*);
char cpcio_getc_is(struct __istream*);
char*cpcio_gtoken_is(struct __istream*);
void cpcio_use_delim(struct __istream*,const char*);
char*cpcio_get_delim(struct __istream*);
typedef struct __istream*istream;
#endif
#endif
