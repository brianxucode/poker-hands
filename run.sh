#!/bin/bash

# Pull tarball
wget -q "https://drive.google.com/uc?export=download&id=1WkN7vKuLlPW0OGrY58raRdkZwnUhausl" -O hw04.tar.gz
tar xzf hw04.tar.gz

echo "Compiling..."
mkdir build
cd build
RELEASE=ON CC=clang CXX=clang++ cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .. || exit 1
make || exit 1

# Return to root folder (so cwd is correct)
cd ..

# Run graded tests
echo "Running graded tests..."
timeout 30 build/tests/tests [graded] || exit 1

