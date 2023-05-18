#include <stdio.h>
#include <libpmem.h>
#include <string.h>

int main()
{
  const char *msg = pmem_errormsg();
  printf("Hello, pmem_errormsg = [%s] (%ld) at %p\n", msg, strlen(msg), msg);
}
