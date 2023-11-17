#!/bin/bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c ./tests/*.c -o test
if [ $? -eq 0 ]; then
    chmod +x test
    ./test
fi