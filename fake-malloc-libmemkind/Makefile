CFLAGS += -Wall -Wextra -g3 -std=c99
EXE = fake-malloc mymalloc.so
DEBUG = mymalloc
TEST_FILES = out.txt

all: $(EXE)
debug: $(DEBUG)
both: $(EXE) $(DEBUG)

mymalloc.so: mymalloc.c
	gcc -Wall -fPIC -shared -o mymalloc.so mymalloc.c -ldl

mymalloc: mymalloc.c
	$(CC) $(CFLAGS) mymalloc.c -o mymalloc -ldl

clean:
	$(RM) $(EXE) $(DEBUG) $(TEST_FILES)
