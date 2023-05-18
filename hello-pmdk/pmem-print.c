#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include "shared-memory.h"

int main() {
    int shm_id;
    Data *shm_ptr;

    // Get the shared memory segment
    shm_id = shmget(SHM_KEY, sizeof(Data), 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to the shared memory segment
    shm_ptr = (Data *)shmat(shm_id, NULL, 0);
    if (shm_ptr == (Data *)(-1)) {
        perror("shmat");
        exit(1);
    }

    // Print the stored data
    for (int i = 0; i < 3; i++) {
        printf("Data[%d]: %d\n", i, shm_ptr->values[i]);
    }

    // Detach from the shared memory segment
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}
