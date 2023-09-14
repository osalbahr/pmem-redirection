#define _GNU_SOURCE
#include <stddef.h>

char file[] = "mello";

int open(const char *pathname, int flags) {
    return 0;
}

size_t read(int fd, void *buf, size_t count) {
    char *temp = buf;
    for (int i = 0; i < count; i++)
        temp[i] = file[i];
    return 0;
}
