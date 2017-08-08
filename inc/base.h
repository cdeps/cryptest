#ifdef __cplusplus
extern "C" {
#endif

int encrypt( unsigned int mult, unsigned int modulo, unsigned int padding );
int decrypt( unsigned int mult, unsigned int modulo, unsigned int padding );
int sign( unsigned int mult, unsigned int modulo, unsigned int padding );

#ifdef __cplusplus
} // extern "C"
#endif


