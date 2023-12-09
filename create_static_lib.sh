#!/bin/bash
library="$1"
for i in *.c
do
	gcc -c "$i" -o "${i%.c}.o"
	ar -rcs "$library" "${i%.c}.o"
done
