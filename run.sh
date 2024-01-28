#!/usr/bin/env zsh

set -x

cd ./src

gcc -g -Wall -fsanitize=leak main.c comment.c platform.c post.c

./a.out

rm -rf *.out