#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

#include "base.h"

unsigned int atoui( char *in ) {
  return strtoul( in, NULL, 10 );
}

#ifdef __cplusplus
} // extern "C"
#endif
