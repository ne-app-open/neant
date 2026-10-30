#!/bin/sh

THIS_PATH="$(realpath "$0")"
THIS_DIR="$(dirname "$THIS_PATH")"
FILE_LIST="$(find "$THIS_DIR" | grep -E ".*(\.cpp|\.cc|\.c|\.h|\.inl)$")"

clang-format --verbose -i --style=file $FILE_LIST
