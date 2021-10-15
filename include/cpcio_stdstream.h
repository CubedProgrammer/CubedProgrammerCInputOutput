#ifndef __cplusplus
#ifndef Included_cpcio_stdstream_h
#define Included_cpcio_stdstream_h
#include<cpcio_istream.h>
#include<cpcio_ostream.h>
extern struct cpcio____istream*cpcio_stdin;
extern struct cpcio____ostream*cpcio_stdout;
extern struct cpcio____ostream*cpcio_stderr;
struct cpcio____istream*cpcio_get_stdin(void);
struct cpcio____ostream*cpcio_get_stdout(void);
struct cpcio____ostream*cpcio_get_stderr(void);
#endif
#endif
