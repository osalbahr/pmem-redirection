#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd = open("hello.txt", O_RDONLY);
	char s[5 + 1] = {};
	read(fd, s, 5);
	printf("%s\n", s);
}
