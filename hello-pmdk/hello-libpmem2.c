#include <stdio.h>
#include <libpmem2.h>
#include <string.h>

int main()
{
  const char *msg = pmem2_errormsg();
  printf("Hello, pmem_errormsg = [%s] (%ld)\n", msg, strlen(msg));
}
