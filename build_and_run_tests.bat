@echo off

:: build test executable
gcc -Wdouble-promotion -Wall -Wextra -std=c99 -IDoubleLinkedList/ DoubleLinkedList/DoubleLinkedList.c main.c unity/unity.c -o main

:: run test (if it returns 0 then pass else it failed)
main.exe