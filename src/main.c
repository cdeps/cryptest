#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <unistd.h>

#include "base.h"

int usage( char *name ) {
  fprintf(stderr, "Usage:\n");
  fprintf(stderr, "  %s -h\n", name);
  fprintf(stderr, "  %s [-e|-d] [-t mul] [-m mod] [-p pad]\n", name);
  fprintf(stderr, "  %s -s [-t mul] [-m mod]\n", name);
  fprintf(stderr, "Options:\n");
  fprintf(stderr, "  -d  Decrypt stdin\n");
  fprintf(stderr, "  -e  Encrypt stdin\n");
  fprintf(stderr, "  -h  Show this usage\n");
  fprintf(stderr, "  -s  Output sign for stdin\n");
  fprintf(stderr, "  -t  Set the multiplicand (default: 13)\n");
  fprintf(stderr, "  -m  Set the modulo (default: 557)\n");
  fprintf(stderr, "  -p  Set the padding in bytes (default: 1)\n");
  return 0;
}

int main( int argc, char **argv ) {
  int opt;

  unsigned int mult = 13, modulo = 557, padding = 1;
  char mode = 0;
  
  while((opt=getopt(argc,argv,"edsht:m:p:"))!=-1) {
    switch(opt) {
      case 'e':
        mode = 1;
        break;
      case 'd':
        mode = 2;
        break;
      case 's':
        mode = 3;
        break;
      case 't':
      case 'm':
      case 'p':
      case 'h':
        return usage( *argv );
      default:
        fprintf(stderr,"Run '%s -h' for usage.\n", *argv);
        return 1;
    }
  }

  switch(mode) {
    case 1: return encrypt( mult, modulo, padding );
    case 2: return decrypt( mult, modulo, padding );
    case 3: return sign( mult, modulo, padding );
  }

  usage( *argv );
  return 2;
}

#ifdef __cplusplus
} // extern "C"
#endif
