#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include "shared-memory.h"

int main() {
    int shm_id;
    Data *shm_ptr;

    // Create a shared memory segment
    shm_id = shmget(SHM_KEY, sizeof(Data), IPC_CREAT | 0666);
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

    // Store data in shm_ptr
    shm_ptr->values[0] = 'A';
    shm_ptr->values[1] = 'B';
    shm_ptr->values[2] = 'C';

    // Detach from the shared memory segment
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}
