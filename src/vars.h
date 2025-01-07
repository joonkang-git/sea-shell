/* XXX DO NOT MODIFY THIS FILE XXX */
#pragma once
/** @file Shell variables */

/** sets a shell variable to value
 *  @returns 0 on success
 *  @returns -1 on error and sets `errno` (see exceptions)
 *
 *  @exception EINVAL name or value is a null pointer
 *  @exception EINVAL name is not a valid variable name
 *  @exception ENOMEM not enough memory to record variable
 *
 *  Auto-exports if the shell variable is already marked for export
 */
int vars_set(char const *name, char const *value);

/** gets the value of a shell variable
 *  @returns 0 on success
 *  @returns -1 on error and sets `errno` (see exceptions)
 *
 *  @exception EINVAL name is a null pointer
 *  @exception EINVAL name is not a valid variable name
 *
 *  @return pointer to value, or null pointer if unset */
char const *vars_get(char const *name);

/** unsets a shell variable
 *  @returns 0 on success
 *  @returns -1 on error and sets `errno` (see exceptions)
 *
 *  @exception EINVAL name is a null pointer
 *  @exception EINVAL name is not a valid variable name
 *
 *  Removes exported variables from the environment
 */
int vars_unset(char const *name);

/** Marks a shell variable for export
 *  @returns 0 on success
 *  @returns -1 on error and sets `errno` (see exceptions)
 *
 *  @exception EINVAL name is a null pointer
 *  @exception EINVAL name is not a valid variable name
 *  @exception ENOMEM not enough memory to record variable
 *
 *  If variable is unset, it will be marked for export
 *  and exported the next time a value is assigned to it.
 */
int vars_export(char const *name);

/** predicate for checking if a variable name is valid
 *  @returns 1 if valid
 *  @returns 0 if invalid
 *  @returns -1 on error and sets `errno` (see exceptions)
 *
 *  @exception EINVAL name is a null pointer
 */
int vars_is_valid_varname(char const *name);

/** frees all var records (prior to exiting)
 */
void vars_cleanup(void);
