CFLAGS = -std=gnu99 -Wall -Wextra -O3
EXE = hello-libpmem hello-libpmemobj
WORKFLOW = pmem_store pmem_print
LDLIBS = -lpmem -lpmemobj
PMEM_FILE_PATH = pmem_file
WORKFLOW_FILE = numbers.txt

all: $(EXE) $(WORKFLOW)

test: all test_pmdk test_worfklow check

test_pmdk:
	$(foreach var,$(EXE),./$(var) &&) echo -n

test_worfklow:
	rm -f $(PMEM_FILE_PATH)
	./pmem_store && ./pmem_print | tee $(WORKFLOW_FILE)

check:
	./check.sh

clean:
	$(RM) $(EXE) $(WORKFLOW) $(PMEM_FILE_PATH) $(TEMP_FILES)
