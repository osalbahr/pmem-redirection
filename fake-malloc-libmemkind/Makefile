CFLAGS = -Wall -Wextra -g3 -std=c99
EXE = fake-malloc mymalloc.so
DEBUG = mymalloc optanemalloc optanemalloc.so
TEST_FILES = out.txt

all: $(EXE)
debug: $(DEBUG)
both: $(EXE) $(DEBUG)

mymalloc.so: mymalloc.c
	gcc -Wall -fPIC -shared -o mymalloc.so mymalloc.c -ldl

optanemalloc.so: optanemalloc.c
	gcc -Wall -fPIC -shared -o optanemalloc.so optanemalloc.c -lmemkind

mymalloc: mymalloc.c
	$(CC) $(CFLAGS) mymalloc.c -o mymalloc -ldl

optanemalloc: optanemalloc.c
	$(CC) $(CFLAGS) optanemalloc.c -o optanemalloc -ldl

clean:
	$(RM) $(EXE) $(DEBUG) $(TEST_FILES)
