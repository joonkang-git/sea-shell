/* XXX DO NOT MODIFY THIS FILE XXX */
#pragma once

#include "parser.h"

struct builtin_redir {
  int pseudofd;
  int realfd;
  struct builtin_redir *next;
};

/* This is a function pointer typedef, representing functions with type
 * signature: int f(struct command *, struct builtin_redir const *redir_list)
 *
 * Yep, C's type system is a doozy! Aren't you glad you don't need to do this
 * yourself? :)
 */
typedef int (*builtin_fn)(struct command *, struct builtin_redir const *redir);

/** Look up corresponding builtin function for a given command
 *  Built-ins simulate real programs while running entirely with-
 *  in the shell itself. They can perform important tasks that
 *  are not possible with separate child processes.
 */
extern builtin_fn get_builtin(struct command *cmd);

