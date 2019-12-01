PYB=/home/${USER}/.pyenv/versions/3.8.0/
PC=$(PYB)bin/python3.8-config
PYCFLAGS=$(shell $(PC) --cflags)
PYLDFLAGS=$(shell $(PC) --ldflags --embed)

BASH_SRC=/home/${USER}/slask/pybash/git/bash

BASH_O_GCCFLAGS=-fPIC -DHAVE_CONFIG_H -DSHELL -g -O2 -Wno-parentheses -Wno-format-security 
BASH_O_CFLAGS=-I$(BASH_SRC)/examples \
	      -I$(BASH_SRC)/examples/loadables \
	      -I$(BASH_SRC) \
	      -I$(BASH_SRC)/lib \
	      -I$(BASH_SRC)/builtins \
	      -I$(BASH_SRC)/include

all: pybash

pybash.o:
	export LD_RUN_PATH="$(PYB)/lib" && \
	gcc $(BASH_O_GCCFLAGS) $(BASH_O_CFLAGS) $(PYCFLAGS) -c -o pybash.o pybash.c

pybash: pybash.o
	gcc -shared -Wl,-soname,pybash $(PYCFLAGS) $(PYLDFLAGS) -L./lib/termcap -o pybash pybash.o

.PHONY: clean
clean:
	/bin/rm -f pybash pybash.o
.PHONY: test
test:
	echo $$$$; \
	bash -c 'echo $$$$; \
	         eval "$$(pyenv init -)"; \
		 export PYTHONHOME=$(PYB); \
		 export LD_LIBRARY_PATH=$(PYB)/lib/:$(PYB)/lib/python3.8/config-3.8-x86_64-linux-gnu/:$(PYB); \
		 pyenv shell 3.8.0; \
		 enable -f ./pybash pybash && \
		 pybash; \
		 echo $$$$'; \
	echo $$$$
