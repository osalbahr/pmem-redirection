#!/bin/bash

set -e

n=3
A=65
WORKFLOW_FILE=numbers.txt

for ((i=0;i<n;i++))
do
	grep "Data\[$i\]: $((A++))" $WORKFLOW_FILE
done

echo "CHECK SUCCESS"
