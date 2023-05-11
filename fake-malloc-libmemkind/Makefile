CFLAGS += -Wall -Wextra -g3 -std=c99
EXE = fake-malloc mymalloc.so
DEBUG = mymalloc

all: $(EXE)
debug: $(DEBUG)
both: $(EXE) $(DEBUG)

mymalloc.so: mymalloc.c
	gcc -Wall -fPIC -shared -o mymalloc.so mymalloc.c -ldl

mymalloc: mymalloc.c
	$(CC) $(CFLAGS) mymalloc.c -o mymalloc -ldl

clean:
	$(RM) $(EXE)
