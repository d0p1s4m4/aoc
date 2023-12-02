#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFF_SIZE 512

char *digits_str[] = {
  "one", "two", "three",
  "four", "five", "six",
  "seven", "eight", "nine",
  NULL
};

int
search_for_digit_str(const char *str)
{
  int i;

  for (i = 0; digits_str[i] != NULL; i++)
    {
      if (strncmp(digits_str[i], str, strlen(digits_str[i])) == 0)
	{
	  return (i + 1);
	}
    }

  return (0);
}

int
parse_line(const char *str)
{
  int n1;
  int n2;
  int tmp;

  n1 = -1;
  n2 = -1;
  while (*str != '\0')
    {
      if ((tmp = search_for_digit_str(str)) != 0)
	{
	  n2 = tmp;
	}
      else if (isdigit((int)*str))
	{
	  n2 = *str - '0';
	}


      if (n1 <= 0 && n2 > 0)
	{
	  n1 = n2;
	}
      str++;
    }

  return (n1 * 10 + n2);
}

int
parse_data(FILE *fp)
{
  char buffer[BUFF_SIZE];
  int result;
  int i;
  int c;

  i = 0;
  result = 0;

  while ((c = fgetc(fp)) != EOF)
    {
      if (c == '\n')
	{
	  buffer[i] = '\0';
	  result += parse_line(buffer);
	  i = 0;
	}
      else
	{
	  buffer[i++] = c;
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
