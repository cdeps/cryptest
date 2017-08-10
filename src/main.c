#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <unistd.h>

#include "base.h"

int usage( char *name ) {
  fprintf(stderr, "\n"
                  "Usage:\n"
                  "  %s -h\n"
                  "  %s [-e|-d] [-t mul] [-m mod] [-p pad]\n"
                  "  %s -s [-t mul] [-m mod]\n", name, name, name );
  fprintf(stderr, "\n"
                  "Options:\n"
                  "  -d  Decrypt stdin\n"
                  "  -e  Encrypt stdin\n"
                  "  -h  Show this usage\n"
                  "  -s  Output sign for stdin\n"
                  "  -t  Set the multiplicand (default: 13)\n"
                  "  -m  Set the modulo (>=128) (default: 66066)\n"
                  "  -p  Set the padding in bytes (>=1) (default: 1)\n");
  fprintf(stderr, "\n");
  return 0;
}

int main( int argc, char **argv ) {
  int opt;

  unsigned int mult = 13, modulo = 66066, padding = 1;
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
        mult = atoui( optarg );
        break;
      case 'm':
        modulo = atoui( optarg );
        if ( modulo < 128 ) {
          fprintf(stderr, "Modulo must be >= 128\n");
          return 3;
        }
        break;
      case 'p':
        padding = atoui( optarg );
        if ( padding < 1 ) {
          fprintf(stderr, "Padding must be >= 1\n");
          return 4;
        }
        break;
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
    case 3: return sign( mult, modulo );
  }

  usage( *argv );
  return 2;
}

#ifdef __cplusplus
} // extern "C"
#endif
