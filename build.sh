#!/bin/bash

echo "building to bin/btree_test"
cd `pwd`/src/
gcc -g btree.c -o ../bin/btree_test
echo "done"
