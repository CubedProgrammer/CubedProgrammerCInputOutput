#ifndef __cplusplus
#ifndef Included_ostream_h
#define Included_ostream_h
#include<stdio.h>
#include<stdlib.h>
struct cpcio____ostream;
void cpcio_flush_os(struct cpcio____ostream*);
int closeos(struct cpcio____ostream*);
struct cpcio____ostream*openos(void*,int(*)(void*,const char*,size_t),int(*)(void*));
void cpcio_putc_os(struct cpcio____ostream*,const char);
void cpcio_puts_os(struct cpcio____ostream*,const char*);
void cpcio_putln_os(struct cpcio____ostream*,const char*);
void cpcio_psqln_os(struct cpcio____ostream*,char**begin,char**end);
void cpcio_putint_os(struct cpcio____ostream*,int);
void cpcio_putl_os(struct cpcio____ostream*,long);
void cpcio_putll_os(struct cpcio____ostream*,long long);
void cpcio_putull_os(struct cpcio____ostream*,unsigned long long);
void cpcio_putf_os(struct cpcio____ostream*,float);
void cpcio_putd_os(struct cpcio____ostream*,double);
void cpcio_plnint_os(struct cpcio____ostream*,int);
void cpcio_plnl_os(struct cpcio____ostream*,long);
void cpcio_plnll_os(struct cpcio____ostream*,long long);
void cpcio_plnull_os(struct cpcio____ostream*,unsigned long long);
void cpcio_plnf_os(struct cpcio____ostream*,float);
void cpcio_plnd_os(struct cpcio____ostream*,double);
void*cpcio_dest_os(struct cpcio____ostream*);
typedef struct cpcio____ostream*ostream;
#endif
#endif
