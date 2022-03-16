#!/bin/sh
cat /etc/passwd | grep -v '#' | awk '{if (NR%2==0) print}' | cut -d ':' -f 1 | rev | sort -r | sed -n "$FT_LINE1, $FT_LINE2 p" | tr "\n" "," | sed 's/,/, /g' | rev | sed 's/ ,/./' | rev | tr -d '\n' 
