/* Bash builtin to be dynamically loaded with enable -f and creates a new
   builtin, called bashpy. */

/* See Makefile for compilation details. */

#define DISABLE_MALLOC_WRAPPERS 1

#include <config.h>

#if defined (HAVE_UNISTD_H)
#  include <unistd.h>
#endif

#include <stdio.h>

#include "loadables.h"

#define PY_SSIZE_T_CLEAN
#include <Python.h>

extern char **make_builtin_argv ();

int
bashpy_main(argc, argv)
int    argc;
char   **argv;
{
    Py_Initialize();
    PyRun_SimpleString(argv[1]);
    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    fflush (stdout);
    return (EXECUTION_SUCCESS);
}

int
bashpy_builtin (list)
WORD_LIST *list;
{
    char **v;
    int c, r;
    v = make_builtin_argv(list, &c);
    r = bashpy_main(c, v);
    free(v);
    return r;
}

int
bashpy_builtin_load (s)
     char *s;
{
  printf ("bashpy builtin loaded\n");
  fflush (stdout);
  return (1);
}

void
bashpy_builtin_unload (s)
     char *s;
{
  printf ("bashpy builtin unloaded\n");
  fflush (stdout);
}

char *bashpy_doc[] = {
	"BashPy builtin.",
	"",
	"this is the long doc for the bashpy builtin",
	(char *)NULL
};

struct builtin bashpy_struct = {
	"bashpy",		/* builtin name */
	bashpy_builtin,		/* function implementing the builtin */
	BUILTIN_ENABLED,	/* initial flags for builtin */
	bashpy_doc,		/* array of long documentation strings. */
	"bashpy <pythoncode>",	/* usage synopsis; becomes short_doc */
	0			/* reserved for internal use */
};
