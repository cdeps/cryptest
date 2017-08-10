#ifdef __cplusplus
extern "C" {
#endif

unsigned int atoui( char *in );

int encrypt( unsigned int mult, unsigned int modulo, unsigned int padding );
int decrypt( unsigned int mult, unsigned int modulo, unsigned int padding );
int sign( unsigned int mult, unsigned int modulo );

#ifdef __cplusplus
} // extern "C"
#endif


