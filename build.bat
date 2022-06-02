@echo off

mkdir build
pushd build
cl -Zi ..\data-structures\stackll.c
popd