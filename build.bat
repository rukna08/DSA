@echo off

mkdir build
pushd build
cl -Zi ..\data-structures\stack.c
popd