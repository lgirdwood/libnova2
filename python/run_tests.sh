#!/bin/bash
# Helper script to run python unit tests using the locally built library

# Find the build directory, fallback to src/.libs if built with autotools
if [ -d "../build/src" ]; then
    LIB_DIR="../build/src"
elif [ -d "../src/.libs" ]; then
    LIB_DIR="../src/.libs"
else
    echo "Warning: No build directory found. You may need to compile libnova first."
    LIB_DIR=""
fi

echo "Running Python Unit Tests using library path: $LIB_DIR"

export LD_LIBRARY_PATH="$(cd "$LIB_DIR" && pwd):$LD_LIBRARY_PATH"
export PYTHONPATH="$(pwd):$PYTHONPATH"

# Run tests
python3 -m unittest discover tests

if [ $? -eq 0 ]; then
    echo "All python unit tests passed!"
else
    echo "Some python unit tests failed!"
    exit 1
fi
