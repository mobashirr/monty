#!/bin/bash

# Create a new directory called 'include'
mkdir include

# set new header file name
header_file="header.h"

echo "" > $header_file

# move c source files:
for source in *.c; do
  if [ "$source" != "main.c" ]; then
    mv "$source" include/
  fi
done
# move c header files:
for head_h in *.h; do
 if [ "$head_h" != "$header_file" ]; then
 mv "$head_h" include/
 fi
done


echo "#ifndef HEAD_H" >> "$header_file"
echo "#define HEAD_H" >> "$header_file"

# include the c  files to the new header:
for head in include/*.h; do
if [ "$head" != "$header_file" ]; then
 echo "#include \"./$head\"" >> "$header_file"
fi
done

for file in include/*.c; do
if [ "$file" != "main.c" ]; then
  echo "#include \"./$file\"" >> "$header_file"
fi
done


echo "#endif" >> "$header_file"

echo "Header file $header_file created successfully!"

