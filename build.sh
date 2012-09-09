#!/bin/bash
VERSION=0.1
echo ">>>> Building libtree ${VERSION}"
cd `pwd`/src/
echo ">>>> Building the test to bin/libtree_test"
gcc -g btree.c node.c tree.c debug.c -o ../bin/btree_test
echo ">>>> Building the shared library to lib/libtree.so.1"
gcc -c -fPIC node.c -o ../lib/node.o
gcc -c -fPIC tree.c -o ../lib/tree.o
gcc -c -fPIC debug.c -o ../lib/debug.o
cd ../lib/
gcc -shared -Wl,-soname,libtree.so.1 -o ../lib/libtree.so.1 node.o tree.o debug.o
echo ">>>> Copying header to lib/libtree.h"
cp -v ../src/libtree.h .
echo ">>>> Done"
