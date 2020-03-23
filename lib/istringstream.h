#ifndef __cplusplus
#ifndef Included_istringstream_h
#define Included_istringstream_h
struct __istringstream;
int closeiss(struct __istringstream*);
struct __istringstream*openiss(const char*);
char cpcio_getc_iss(struct __istringstream*);
char*cpcio_gtoken_iss(struct __istringstream*);
void cpcio_udelim_iss(struct __istringstream*,const char*);
char*cpcio_gdelim_iss(struct __istringstream*);
int cpcio_gint_iss(struct __istringstream*);
long cpcio_glong_iss(struct __istringstream*);
long long cpcio_gll_iss(struct __istringstream*);
unsigned long long cpcio_gull_iss(struct __istringstream*);
float cpcio_gfloat_iss(struct __istringstream*);
double cpcio_gdouble_iss(struct __istringstream*);
typedef struct __istringstream*istringstream;
#endif
#endif
