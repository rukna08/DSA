@echo off

mkdir build
pushd build
cl -Zi ..\data-structures\queue.c
popd