#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#include "base.h"

int decrypt( unsigned int mult, unsigned int modulo, unsigned int padding ) {

  // Initialize variables
  unsigned long long seed = 0;
  unsigned long long obuf = 0;
  int obuf_len = 0;
  int i, c;

  // Read padding & build seed
  padding--;
  seed = fgetc(stdin);
  while( padding-- ) {
    seed = seed * mult;
    seed = seed % modulo;
    c = (seed%256) ^ fgetc(stdin);
    seed ^= c;
  }

  while( 1 ) {

    // Handle stdin
    c = fgetc(stdin);
    if(c==EOF) break;
    seed = ((seed*mult)+c)%modulo;
    obuf = (obuf%(1<<obuf_len))<<7;
    obuf |= seed%128;
    obuf_len += 7;
    if(obuf_len>=8) {
      fputc( (obuf>>(obuf_len-8))%256, stdout );
      obuf_len-=8;
    }
  }

  return 0;
}

#ifdef __cplusplus
} // extern "C"
#endif
