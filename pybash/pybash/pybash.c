/* Sample builtin to be dynamically loaded with enable -f and create a new
   builtin. */

/* See Makefile for compilation details. */

/*
   Copyright (C) 1999-2009 Free Software Foundation, Inc.

   This file is part of GNU Bash.
   Bash is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Bash is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Bash.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <config.h>

#if defined (HAVE_UNISTD_H)
#  include <unistd.h>
#endif

#include <stdio.h>

#include "loadables.h"

#define PY_SSIZE_T_CLEAN
#include <Python.h>

/*
#int
#main(int argc, char *argv[])
#{
#    wchar_t *program = Py_DecodeLocale(argv[0], NULL);
#    if (program == NULL) {
#        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
#        exit(1);
#    }
#    Py_SetProgramName(program);
#    Py_Initialize();
#    PyRun_SimpleString("from time import time,ctime\n"
#                       "print('Today is', ctime(time()))\n");
#    if (Py_FinalizeEx() < 0) {
#        exit(120);
#    }
#    PyMem_RawFree(program);
#    return 0;
#}
*/

/* A builtin `xxx' is normally implemented with an `xxx_builtin' function.
   If you're converting a command that uses the normal Unix argc/argv
   calling convention, use argv = make_builtin_argv (list, &argc) and call
   the original `main' something like `xxx_main'.  Look at cat.c for an
   example.

   Builtins should use internal_getopt to parse options.  It is the same as
   getopt(3), but it takes a WORD_LIST *.  Look at print.c for an example
   of its use.

   If the builtin takes no options, call no_options(list) before doing
   anything else.  If it returns a non-zero value, your builtin should
   immediately return EX_USAGE.  Look at logname.c for an example.

   A builtin command returns EXECUTION_SUCCESS for success and
   EXECUTION_FAILURE to indicate failure. */

int
pybash_builtin (list)
    WORD_LIST *list;
{
    /*
    char* pypath="pybash";
    wchar_t *program = Py_DecodeLocale(pypath, NULL);
    if (program == NULL) {
        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
        exit(1);
    }
    Py_SetProgramName(program);
    */

    //wchar_t const* pyhome = L"/home/flux/.pyenv/versions/3.8.0";
    //Py_SetPythonHome(pyhome);
    Py_Initialize();
    PyRun_SimpleString("from time import time,ctime\n"
                       "print('Today is', ctime(time()))\n");
    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    //PyMem_RawFree(program);
    fflush (stdout);
    return (EXECUTION_SUCCESS);
}

int
pybash_builtin_load (s)
     char *s;
{
  printf ("pybash builtin loaded\n");
  fflush (stdout);
  return (1);
}

void
pybash_builtin_unload (s)
     char *s;
{
  printf ("pybash builtin unloaded\n");
  fflush (stdout);
}

char *pybash_doc[] = {
	"PyBash builtin.",
	"",
	"this is the long doc for the pybash builtin",
	(char *)NULL
};

struct builtin pybash_struct = {
	"pybash",		/* builtin name */
	pybash_builtin,		/* function implementing the builtin */
	BUILTIN_ENABLED,	/* initial flags for builtin */
	pybash_doc,		/* array of long documentation strings. */
	"pybash",		/* usage synopsis; becomes short_doc */
	0			/* reserved for internal use */
};
