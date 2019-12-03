SHELL = bash
PYB=/home/${USER}/.pyenv/versions/3.8.0/
PC=$(PYB)bin/python3.8-config
PYCFLAGS=$(shell $(PC) --cflags)
PYLDFLAGS=$(shell $(PC) --ldflags --embed)
BASH_SRC=/home/${USER}/slask/bashpy/git/bash
BASH_O_GCCFLAGS=-fPIC \
		-DHAVE_CONFIG_H \
		-DSHELL \
		-g -O2 \
		-Wno-parentheses \
		-Wno-format-security
BASH_O_CFLAGS=-I$(BASH_SRC)/examples \
	      -I$(BASH_SRC)/examples/loadables \
	      -I$(BASH_SRC) \
	      -I$(BASH_SRC)/lib \
	      -I$(BASH_SRC)/builtins \
	      -I$(BASH_SRC)/include

.PHONY: all
all: bashpy

bashpy.o:
	export LD_RUN_PATH="$(PYB)/lib" && \
	gcc $(BASH_O_GCCFLAGS) \
	    $(BASH_O_CFLAGS) \
	    $(PYCFLAGS) \
	    -c -o bashpy.o bashpy.c

bashpy: bashpy.o
	gcc -shared \
	    -Wl,-soname,bashpy \
	    -L./lib/termcap \
	    -Wl,-rpath,$(PYB)/lib \
	    $(PYCFLAGS) \
	    -Wl,-no-as-needed \
	    $(PYLDFLAGS) \
	    -Wl,-as-needed \
	    -o bashpy \
	    bashpy.o

.PHONY: clean
clean:
	/bin/rm -f bashpy bashpy.o

define _py
# This multi-line variable needs some escaping
# ex: f"{{var}}" won't work but f"{{{var}}}" will.
import sys
print("hello world from python " + sys.version)
print(f"version_info:{{{sys.version_info}}}")
endef
export py = $(value _py)
.PHONY: test
test:
	@echo $$$$
	@echo $$$$; \
	  enable -f ./bashpy bashpy && \
	  bashpy "$$py" && \
	  echo $$$$
	@echo $$$$
