CFLAGS += -Wall -g3 -std=c99
EXE = fancy-file-io myio.so
TEST = myio
LDLIBS = -ldl

all: $(EXE)

test: $(TEST)
both: $(EXE) $(TEST)

myio.so: myio.c
	gcc -Wall -fPIC -shared -o myio.so myio.c -ldl

myio: myio.c
	$(CC) $(CFLAGS) myio.c -o myio -ldl

clean:
	$(RM) $(EXE) $(TEST)
