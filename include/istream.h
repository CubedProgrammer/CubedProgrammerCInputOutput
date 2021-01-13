#ifndef __cplusplus
#ifndef Included_istream_h
#define Included_istream_h
#include<stdio.h>
struct cpcio____istream;
int closeis(struct cpcio____istream*);
struct cpcio____istream*openis(void*,int(*)(void*,char*,size_t),int(*)(void*));
char cpcio_getc_is(struct cpcio____istream*);
void cpcio_ungetc_is(struct cpcio____istream*);
char*cpcio_gtoken_is(struct cpcio____istream*);
void cpcio_use_delim(struct cpcio____istream*,const char*);
char*cpcio_get_delim(struct cpcio____istream*);
int cpcio_gint_is(struct cpcio____istream*);
long cpcio_glong_is(struct cpcio____istream*);
long long cpcio_gll_is(struct cpcio____istream*);
unsigned long long cpcio_gull_is(struct cpcio____istream*);
float cpcio_gfloat_is(struct cpcio____istream*);
double cpcio_gdouble_is(struct cpcio____istream*);
void*cpcio_src_is(struct cpcio____istream*);
typedef struct cpcio____istream*istream;
#endif
#endif
