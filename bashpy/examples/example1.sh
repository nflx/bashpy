#!/bin/bash
enable -f ../bashpy/bashpy bashpy
read -r -d '' PY <<-'PY'
if True:
  print("hello world")
PY
bashpy "$PY"
