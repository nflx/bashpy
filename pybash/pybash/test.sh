#!/bin/bash
enable -f ./pybash pybash
read -r -d '' PY <<-'PY'
if True:
  print("hello world")
PY
pybash "$PY"
