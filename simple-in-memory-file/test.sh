#!/usr/bin/bash

set -e

if ! make
then
    echo "FAILED to compile"
    exit 1
fi

test()
{
    ./main \
	&& LD_PRELOAD=./myfopen.so ./main
}

if ! test | tee actual.txt
then
    echo "FAILED to test"
    exit 1
fi

if ! diff expected.txt actual.txt
then
    echo "FAILED files differ"
    exit 1
fi

echo "SUCCESS"
