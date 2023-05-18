#include <libpmem.h>
#include <libpmemobj.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define PMEM_FILE_PATH "~/.pmem/pool.pmem"
#define PMEM_FILE_SIZE 2097152

int main() {
    // Open the persistent memory pool
    PMEMobjpool* pool = pmemobj_open(PMEM_FILE_PATH, "simple_program");
    if (pool == NULL) {
		const char *msg = pmemobj_errormsg();
		printf("pmemobj_errormsg = [%s] (%ld) at %p\n", msg, strlen(msg), msg);
        perror("Failed to open the persistent memory pool");
        return 1;
    }

    // Rest of your code ...

    // Close the persistent memory pool
    pmemobj_close(pool);

    return 0;
}
