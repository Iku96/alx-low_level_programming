#!/bin/bash

# Compile all .c files into object files
for file in *.c; do
    cc -c $file
done

# Create static library from object files
ar -rcs liball.a *.o

# Clean up object files
rm *.o

