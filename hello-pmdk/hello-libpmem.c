#include <stdio.h>
#include <libpmem.h>
#include <string.h>

int main()
{
  const char *msg = pmem_errormsg();
  printf("Hello, pmem2_errormsg = [%s] (%ld)\n", msg, strlen(msg));
}
