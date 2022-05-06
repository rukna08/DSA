@echo off

mkdir build
pushd build
cl -Zi ..\algorithms\quicksort.c Winmm.lib
popd