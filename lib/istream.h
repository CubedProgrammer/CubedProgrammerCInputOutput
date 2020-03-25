#ifndef __cplusplus
#ifndef Included_istream_h
#define Included_istream_h
#include<stdio.h>
struct __istream;
int closeis(struct __istream*);
struct __istream*openis(void*,int(*)(void*,char*,size_t),int(*)(void*));
char cpcio_getc_is(struct __istream*);
char*cpcio_gtoken_is(struct __istream*);
void cpcio_use_delim(struct __istream*,const char*);
char*cpcio_get_delim(struct __istream*);
int cpcio_gint_is(struct __istream*);
long cpcio_glong_is(struct __istream*);
long long cpcio_gll_is(struct __istream*);
unsigned long long cpcio_gull_is(struct __istream*);
float cpcio_gfloat_is(struct __istream*);
double cpcio_gdouble_is(struct __istream*);
typedef struct __istream*istream;
#endif
#endif
