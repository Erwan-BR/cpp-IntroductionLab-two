#!/bin/bash

# 0. Informing the user that the lab is compiling
echo "Compiling all files..."

# 1. Compiling main.cpp and every cpp files found by find.
g++ main.cpp $(find question1/ question2/ question3/ -name "*.cpp") -o TP2

# 2. Checking if compilation worked.
if [ $? -eq 0 ]; then
    # 3. Launching the object file if everything worked.
    ./TP2
    read -p "Type any key to exit."
else
    # 4. If the compilation failed, inform the user.
    read -p "Compilation failed. Type any key to exit."
    # read -n 1 -s
fi

