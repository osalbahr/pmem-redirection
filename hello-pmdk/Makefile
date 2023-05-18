CFLAGS = -std=gnu99 -Wall -Wextra -O3
EXE = hello-libpmem hello-libpmemobj
LDLIBS = -lpmem -lpmemobj

all: $(EXE)

# See https://stackoverflow.com/questions/1490949/how-to-write-loop-in-a-makefile
test: all
	$(foreach var,$(EXE),./$(var) &&) echo -n

clean:
	$(RM) $(EXE)
