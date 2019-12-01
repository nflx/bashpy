PYB=/home/${USER}/.pyenv/versions/3.8.0/
PC=$(PYB)bin/python3.8-config
PYCFLAGS=$(shell $(PC) --cflags)
PYLDFLAGS=$(shell $(PC) --ldflags --embed)

all: today

today:
	gcc $(PYCFLAGS) -o today today.c $(PYLDFLAGS)

.PHONY: clean
clean:
	/bin/rm -f today
