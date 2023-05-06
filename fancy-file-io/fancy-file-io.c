#include <stdio.h>
#include <string.h>

#define REPORTP(P) printf("%s = %p\n", #P, (P))

int main()
{
  FILE *fp = fopen("hi", "a");
  REPORTP(fp);

  char *world = "Hello, World!\n";
  fwrite(world, 1, strlen(world), fp);
  
  char chptr[1];
  while (fread(chptr, 1, 1, fp))
    putchar(*chptr);

  fclose(fp);
}
