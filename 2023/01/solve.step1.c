#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int
parse_data(FILE *fp)
{
  int n1;
  int n2;
  int result;
  int c;

  n1 = -1;
  n2 = -1;
  result = 0;

  while ((c = fgetc(fp)) != EOF)
    {
      if (c == '\n')
	{
	  result += (n1 * 10) + n2;
	  n1 = -1;
	}
      else if (isdigit(c))
	{
	  if (n1 < 0)
	    {
	      n1 = c - '0';
	    }
	  n2 = c - '0';
	}
    }

  return (result);
}

int
main(int argc, char **argv)
{
  FILE *fp;

  if (argc < 2)
    {
      fprintf(stderr, "Usage: %s <input>\n", argv[0]);
      return (EXIT_FAILURE);
    }

  fp = fopen(argv[1], "r");
  if (fp == NULL)
    {
      fprintf(stderr, "Can't open %s\n", argv[1]);
      return (EXIT_FAILURE);
    }
  printf("result: %d\n", parse_data(fp));
  fclose(fp);
  return (EXIT_SUCCESS);
}
