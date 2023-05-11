#include <stdio.h>
#include <stdlib.h>

#define REPORTP(P) printf("%s = %p\n", #P, (P))
#define REPORTI(P) printf("%s = %d\n", #P, (P))
#define REPORTC(P) printf("%s = %c\n", #P, (P))

int main()
{
  int *iptr = malloc(sizeof(int));
  REPORTP(iptr);
  *iptr = 41;
  REPORTI(*iptr);
  free(iptr);

  char *cptr = malloc(sizeof(char));
  REPORTP(cptr);
  *cptr = 'A';
  REPORTC(*cptr);
  free(cptr);

  char *zero = malloc(0);
  REPORTP(zero);
  free(zero);
}
