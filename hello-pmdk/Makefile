CFLAGS = -std=gnu99 -Wall -Wextra -O3
EXE = hello-libpmem hello-libpmem2 hello-libpmemobj
LDLIBS = -lpmem -lpmem2 -lpmemobj

all: $(EXE)

# See https://stackoverflow.com/questions/1490949/how-to-write-loop-in-a-makefile
test: all
	$(foreach var,$(EXE),./$(var) &&) echo -n

clean:
	$(RM) $(EXE)
