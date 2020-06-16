#ifndef __cplusplus
#ifndef Included_ostream_h
#define Included_ostream_h
#include<stdio.h>
#include<stdlib.h>
struct __ostream;
void cpcio_flush_os(struct __ostream*);
int closeos(struct __ostream*);
struct __ostream*openos(void*,int(*)(void*,const char*,size_t),int(*)(void*));
void cpcio_putc_os(struct __ostream*,const char);
void cpcio_puts_os(struct __ostream*,const char*);
void cpcio_putln_os(struct __ostream*,const char*);
void cpcio_psqln_os(struct __ostream*,char**begin,char**end);
void cpcio_putint_os(struct __ostream*,int);
void cpcio_putl_os(struct __ostream*,long);
void cpcio_putll_os(struct __ostream*,long long);
void cpcio_putull_os(struct __ostream*,unsigned long long);
void cpcio_putf_os(struct __ostream*,float);
void cpcio_putd_os(struct __ostream*,double);
void cpcio_plnint_os(struct __ostream*,int);
void cpcio_plnl_os(struct __ostream*,long);
void cpcio_plnll_os(struct __ostream*,long long);
void cpcio_plnull_os(struct __ostream*,unsigned long long);
void cpcio_plnf_os(struct __ostream*,float);
void cpcio_plnd_os(struct __ostream*,double);
void*cpcio_dest_os(struct __ostream*);
typedef struct __ostream*ostream;
#endif
#endif
