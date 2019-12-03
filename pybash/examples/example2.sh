#!/bin/bash
enable -f ../pybash/pybash pybash
read -r -d '' PY <<-'PY'
import os
if __name__ == '__main__':
  print(os.__file__)
  print([a for a in (1,2,3) if a > 1])
PY
pybash "$PY"
