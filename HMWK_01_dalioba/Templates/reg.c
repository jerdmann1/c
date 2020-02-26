/**
 * file   : regex.match.1.c
 * author : John Saxon (09-Mar-2010)
 * revision : $Rev$
 *
 * this program is to demonstrate how to use the POSIX regular
 * expression functions (defined in regex.h).
 *
 * this particular program shows you how to simply say whether
 * a give string (argv[1]) is a match for a given regular
 * expression pattern (argv[2]). So basicllay it returns a
 * yes or no answer.
 */

#include <regex.h>
#include <stdio.h>

int
main(int argc, char **argv)
{
  /**
   * Usage: prog string regex
   * so should have 3 argsuments (inc. program name)
   */
  if(argc == 3) /* so should have 3 argsuments (inc. program name) */
  {
    int status;
    /* compiled regex object (well not really an object ...) */
    regex_t regex;

    /* compile a regular expression */
    status = regcomp(&regex, "^\\+\\$*[0-7g-n]+\\^$", REG_EXTENDED | REG_NOSUB);
    if(status == 0) /* success ? */
    {
      /* match the string to the regular expression */
      status = regexec(&regex, "+$0^", (size_t) 0, NULL, 0);
      /* output result */
      printf(
        "match: %c;\n",
        /* a bit of a ternary op here               *
         * if(!failed) return 'y'; else return 'n'; */
        status != REG_NOMATCH ? 'y' : 'n'
      );

    }
    else /* fail */
    {
      /* space for an error message */
      char err[50];

      /* get the error message */
      regerror(status, &regex, err, (size_t) sizeof(err));

      /* print the error message */
      printf("error: %s\n", err);
    }

    /* free the compiled regular expression */
    regfree(&regex);
  }
  /* called incorrectly */
  else
  {
    /* print usage */
    printf("Usage:\n\t%s str pattern\n", argv[0]);
  }

  return 0;
}
