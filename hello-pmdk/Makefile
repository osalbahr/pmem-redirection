EXE = hello-libpmem hello-libpmem2 hello-libpmemobj

all: $(EXE)

# See https://stackoverflow.com/questions/1490949/how-to-write-loop-in-a-makefile
test: all
	$(foreach var,$(EXE),./$(var);)

clean:
	$(RM) $(EXE)
