#ifndef __cplusplus
#ifndef Included_cpcio_ostream_h
#define Included_cpcio_ostream_h
#include<stdio.h>
#include<stdlib.h>
#define cpcio_printf_os(os, format, ...)do{char cbuf[10001];sprintf(cbuf, format, __VA_ARGS__);cpcio_puts_os(os, cbuf);}while(0)
struct cpcio____ostream;
void cpcio_flush_os(struct cpcio____ostream*);
int cpcio_close_ostream(struct cpcio____ostream*);
struct cpcio____ostream*cpcio_open_ostream(void*,int(*)(void*,const char*,size_t),int(*)(void*));
size_t cpcio_wr(struct cpcio____ostream*,const void*,size_t);
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
typedef struct cpcio____ostream*cpcio_ostream;
#endif
#endif
