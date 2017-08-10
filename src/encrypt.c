#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "base.h"

int encrypt( unsigned int mult, unsigned int modulo, unsigned int padding ) {

  // Initialize variables
  unsigned long long seed     = 0;
  unsigned long long ibuf     = 0;
  int flags = 2; // 1=running, 2=input
  int c,e, ibuf_len = 0;

  // Randomize the 'rand' call
  srandom((unsigned)time(NULL));
  for( seed = 5000; seed; rand(), seed-- );

  // Ensure padding
  while( padding-- ) {
    if ( flags & 1 ) {
      seed = seed * mult;
      seed = seed % modulo;
      seed = seed ^ ( random() % 256 );
      fputc( seed % 256, stdout );
    } else {
      seed = random() % 256;
      fputc( seed, stdout );
      flags |= 1;
    }
  }

  // Start encoding
  while( flags & 1 ) {

    // Handle stdin
    if ( ( flags & 2 ) && ( ibuf_len < 7 ) ) {
      if ( (c=fgetc(stdin)) == EOF ) {
        flags &= ~2;
      } else {
        ibuf = ibuf % ( 1 << ibuf_len );
        ibuf = ibuf << 8;
        ibuf |= c;
        ibuf_len += 8;
      }
    }

    // Fetch number to encode
    c = ((ibuf<<7)>>ibuf_len)%128;
    ibuf_len -= 7;

    // Feedback-based encoding
    e = 0;
    seed = seed * mult;
    while( ((seed+e)%modulo)%128 != c ) e++;
    seed = (seed+e)%modulo;
    fputc( e, stdout );

    // EOF detection
    if( ibuf_len <= 0 && !(flags&2) ) {
      flags &= ~1;
    }
  }

  return 0;
}

#ifdef __cplusplus
} // extern "C"
#endif
