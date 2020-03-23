#ifndef __cplusplus
#ifndef Included_ostringstream_h
#define Included_ostringstream_h
struct __ostringstream;
void cpcio_flush_oss(struct __ostringstream*);
int closeoss(struct __ostringstream*);
struct __ostringstream*openoss(char*);
void cpcio_putc_oss(struct __ostringstream*,const char);
void cpcio_puts_oss(struct __ostringstream*,const char*);
void cpcio_putln_oss(struct __ostringstream*,const char*);
void cpcio_psqln_oss(struct __ostringstream*,char**begin,char**end);
void cpcio_plnint_oss(struct __ostringstream*,int);
void cpcio_plnl_oss(struct __ostringstream*,long);
void cpcio_plnll_oss(struct __ostringstream*,long long);
void cpcio_plnull_oss(struct __ostringstream*,unsigned long long);
void cpcio_plnf_oss(struct __ostringstream*,float);
void cpcio_plnd_oss(struct __ostringstream*,double);
char*cpcio_str_oss(struct __ostringstream*);
typedef struct __ostringstream*ostringstream;
#endif
#endif
