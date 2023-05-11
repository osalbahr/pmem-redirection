#define _GNU_SOURCE

#include <stdio.h>
#include <dlfcn.h>

// Link with -lmemkind
// See https://pmem.io/memkind/manpages/memkind.3/
#include <memkind.h>

// #define REPORTP(P) printf("%s = %p\n", #P, (P))

void *malloc(size_t size)
{
  printf("OK, malloc'ing %zd :)\n", size);

  if (size == 0) {
    printf("... shortcut, though\n");
    return NULL;
  }

  return memkind_malloc(MEMKIND_DEFAULT, size);
}

void free(void *ptr)
{
  // TODO: destroy the memory
}

// int main()
// {
//   FILE *fp = fopen("README.md", "r");
//   REPORTP(fp);
// }