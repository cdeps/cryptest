#ifdef __cplusplus
extern "C" {
#endif

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ROT(s,a) ((s<<a)|(s>>(sizeof(s)-a)))

unsigned int atoui( char *in );

int encrypt( unsigned int mult, unsigned int modulo, unsigned int padding );
int decrypt( unsigned int mult, unsigned int modulo, unsigned int padding );
int sign( unsigned int mult, unsigned int modulo );

#ifdef __cplusplus
} // extern "C"
#endif


