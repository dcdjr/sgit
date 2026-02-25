#!/bin/bash

echo "===== PROJECT FILE DUMP ====="
echo

find src include commands -type f \( -name "*.cpp" -o -name "*.hpp" \) | sort | while read file; do
    echo "========================================"
    echo "FILE: $file"
    echo "========================================"
    echo
    cat "$file"
    echo
    echo
done
