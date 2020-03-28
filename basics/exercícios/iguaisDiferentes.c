#include <stdio.h>
#include <string.h>

int main()
{

  char s[3] = "um";
  char t[3] = "um";

  printf("s: %s", s);

  printf("\n");

  if (strcmp(s, t) == 0)
    puts("iguais");
  else
    puts("diferentes");

  return 0;
}