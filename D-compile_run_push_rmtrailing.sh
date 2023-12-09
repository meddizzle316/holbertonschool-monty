#!/usr/bin/env bash
input="$1"
output="${1%.c}.o"
destination="backups/"
comment="$2"

sed --in-place 's/[[:space:]]\+$//' "$input"
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 "$input" -o "$output"
./"$output"
mv "$output" "$destination"
git add .
git commit -m "$comment"
git push
