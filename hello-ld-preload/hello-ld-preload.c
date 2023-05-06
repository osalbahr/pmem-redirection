#include <stdio.h>

#define REPORTP(P) printf("%s = %p\n", #P, (P))

int main()
{
  char *filename = "README.md";
  FILE *fp = fopen(filename, "r");
  REPORTP(fp);
  if (fp == NULL) {
    puts("You've been pwn'd");
    perror(filename);
  } else {
    puts("Success!");
    perror(filename);
  }

  char *bad = "bad";
  fp = fopen(bad, "r");
  REPORTP(fp);
  if (fp == NULL) {
    perror(bad);
  } else {
    puts("Success!");
    perror(bad);
  }
}
