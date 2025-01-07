BigShell
========

**If you make a fork of this repository, ensure that you set it to private before uploading any of your own work. Publicly sharing your work on this assignment is prohibited by OSU's Code of Student Conduct and will be reported.**

**DO NOT MAKE PULL REQUESTS TO THIS REPOSITORY. WHEN YOU DO THIS, YOU ARE SHARING ALL OF YOUR CODE PUBLICLY AND IT CANNOT BE REMOVED. Failure to follow these instructions may result in grade penalties!!!**

The provided makefile can be used to build your project,
 
.. code-block:: console

   $ make          # Equivalent to `make all`
   $ make all      # Equivalent to `make release debug` (default target)
   $ make release  # Release build in release/ -- no debugging messages
   $ make debug    # Debug build in debug/ -- includes assertions and debugging messages
   $ make clean    # Removes build files (release/ and debug/ directories)

Though there are several files in ``src/`` you will only need to modify a few files to complete the assignment. Specifically:

* ``builtins.c``
* ``signal.c``
* ``vars.c``
* ``runner.c``
* ``wait.c``

A reference implementation is provided in ``reference/bigshell``.
