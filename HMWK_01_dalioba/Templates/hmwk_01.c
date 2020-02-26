// Dalio, Brian A.
// dalioba
// 2020-02-24

#include <ctype.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

regex_t tent;
regex_t aitchpi;
regex_t juggle;


char *getToken( FILE *fp );

// (Hint: Put your regex_t declarations here.)

//----------------------------------------------------------
void processToken( char *token )
{
  if(!regexec(&tent, token, (size_t)0, NULL, 0)){
    printf(">%s< matches Tent.\n", token);
  }else if(!regexec(&aitchpi, token, (size_t)0, NULL, 0)){
    printf(">%s< matches AitchPi.\n", token);
  }else if(!regexec(&juggle, token, (size_t)0, NULL, 0)){
    printf(">%s< matches Juggle.\n", token);
  }else{
    printf(">%s< does not match.\n", token);
  }
  // Replace the following line with your code to classify
  // the string in 'token' according to your three Regular
  // Expressions and print the appropriate message.
  // (Hint: use regexec() to do the regular expression matching.)
}

//----------------------------------------------------------
int main( int argc, char *argv[] )
{
  // (Hint: Put the initialization of your regular expressions here.
  //        This would be the calls to regcomp().)
  if(0 != (regcomp(&tent, "^\+\$*[0-7g-n]+\^$", 0))){
    printf("Failed to compile Tent\n");
    exit(0);
  }else if(0 != (regcomp(&aitchpi, "^[0-9a-fA-F]*\]\([q-zQ-Z]*$", 0))){
    printf("Failed to compile AithchPi\n");
    exit(0);
  }else if(0 != (regcomp(&juggle, "^\([N-Za-m]+\#$", 0))){
    printf("Failed to compile Juggle\n");
    exit(0);
  }

  // DO NOT CHANGE anything below this line in main()!
  if ( argc > 1 ) {
    printf( "processing tokens from %s ...\n", argv[1] );

    FILE *fp = fopen( argv[1], "r" );
    char *token = NULL;

    if ( fp != NULL ) {
      while ( token = getToken( fp ) ) {
        processToken( token );
        free( token );
      }

      fclose( fp );
    } else {
      printf( "unable to open %s?\n", argv[1] );
    }
  } else {
    printf( "No input file specified.\n" );
  }
}

//----------------------------------------------------------
// DO NOT CHANGE anything below this line!
#define MAX_TOKEN_SIZE (1024)

char *getToken( FILE *fp )
{
  char token[ MAX_TOKEN_SIZE+1 ];
  int  i  = 0;

  while ( i < MAX_TOKEN_SIZE ) {
    int ch = fgetc( fp );

    if ( ch == EOF ) { break; }

    if ( isspace( ch ) ) {
      if ( i == 0 ) { continue; }
      break;
    }

    token[ i++ ] = ch;
  }

  if ( i == 0 ) { return NULL; }

  token[ i ] = '\0';

  return strdup( token );
}

//----------------------------------------------------------
