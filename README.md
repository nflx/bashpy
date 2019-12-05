# Description
Bash loadable module that embeds python as builtin command bashpy,
taking python code as first argument.

# State
It's not very useful but merely a proof of concept. As it doesn't provide the python context any access to bash internals or even support passing it variables.

# Disclaimer
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

# Based on
- The Embedding Python example here:
  https://docs.python.org/3/extending/embedding.html#very-high-level-embedding

- Bash examples/loadables/cat.c
  https://github.com/bminor/bash/blob/master/examples/loadables/cat.c

# Why
I wanted to try building a loadable module after I got notion about the loadable module support in Bash by this video about Suidbash https://www.youtube.com/watch?v=-wGtxJ8opa8.

There already exist loadable modules for other languages as:
- [luabash](https://github.com/alfredopalhares/LuaBash)
- [perl](https://github.com/bminor/bash/tree/master/examples/loadables/perl)

As I found out after some research, but I could not find any python equivalent.

# Install
## Requirements
Exact requirements TBD, but essentially:
- build-essentials
- python dev (tested with: python 3.8.0 from pyenv)
- bash sourcecode (tested with: bash 4.3 from github)
- editing of some hardcoded paths in Makefile

## Prepare
To build the loadable module we need bash sources.
The `getbashsrc.sh` script downloads and configures bash 5.0, update it first to match the bash --version.
```
./getbashsrc.sh
```

Python needs to be built with `--enable-shared`, this is how to do it using pyenv.
```
PYTHON_CONFIGURE_OPTS="--enable-shared" pyenv install 3.8.0
```

Make sure you have pyenv installed/cloned to ~/.pyenv (or symlink it there or change paths in Makefile).
```
make -C bashpy
make -C bashpy test
```

## Examples
See `examples/*.sh` for some info on how to invoke bashpy from a script.

## Troubleshoot

### Bash loadable
Build and test bash loadable `git/bash/examples/loadables/hello` (a "hello world" example).
```
### build
./configure
make pathnames.h
make -C examples/loadables hello

### enable
cd examples/loadables
enable -f $PWD/hello hello

### run
hello
Hello world

### unload
enable -d $PWD/hello hello
hello
<error>
```

### Python embedded
Build and run python embedded example `examples/embedded-python-today/`.
```
cd examples/embedded-python-today/
# Edit the Makefile to point to the correct python.
make
./today
```

# Future ideas
- Support passing/getting variables.
- Support stdin (see `git/bash/examples/loadable/cat.c`).
- Pass the python code as file.
- Support calling functions.
- Make it easier to write code inline compared to examples.

# Credits
- [Luabash](https://github.com/alfredopalhares/LuaBash), for ideas on how to increase the usability.
- [Bash](https://www.gnu.org/software/bash/), for what would my life be without it. Also great docs and examples!
- [Ian Pudney](https://github.com/IanPudney) and [LiveOverflow](https://www.youtube.com/channel/UClcE-kVhqyiHCcjYwcpfj9w) for inspiring me to try and build a bash loadable builtin.

# LICENSE
GPLv3, See the file [COPYING](COPYING)

   Copyright (C) 2019  Emil Lind - `<github@sys.nu>`

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.
