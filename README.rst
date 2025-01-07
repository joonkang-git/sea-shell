Project Structure
The BigShell program is composed of several key files, each responsible for a specific part of the shell's functionality. Below is a breakdown of each file and its role within the project:

bigshell.c – Program Entry Point
The main entry point of the BigShell program is bigshell.c, which contains the REPL (Read-Eval-Print Loop) that continuously reads and parses user commands. It handles signal initialization by calling functions from signal.c to ensure the shell ignores specific signals like SIGTSTP, SIGINT, and SIGTTOU. Once a command is successfully parsed, bigshell.c executes it by calling run_command_list() from runner.c, and then performs cleanup of the command list.

signal.c – Signal Handling
The signal.c file manages all signal-related operations in the shell. It initializes signal handling during the startup process to ignore certain signals (SIGTSTP, SIGINT, SIGTTOU) and provides functions to handle signal interruptions. The file also includes functions to temporarily ignore signals during critical operations and restore previous signal behaviors once the operations are complete.

runner.c – Command Execution
The runner.c file is responsible for executing commands, managing I/O redirections, handling variable assignments, and performing job control. It loops through the command list, expanding each command to determine if it requires variable assignment or redirection, using functions from expand.c. Depending on whether a command is built-in or external, it handles the execution accordingly. For background and foreground processes, runner.c manages the process flow, including creating pipelines and managing I/O redirections for commands in the pipeline. Foreground processes are managed by calling the wait.c file.

vars.c – Environment Variable Management
The vars.c file provides functionality for managing environmental variables. It includes functions to get, set, unset, and export variables in the shell environment. It also validates variable names and searches for variables within the shell's list. This file is crucial for handling the shell’s dynamic environment and ensuring variables are correctly assigned and retrieved.

wait.c – Process Management
The wait.c file manages both foreground and background processes. It handles process groups, sends SIGCONT signals to continue stopped jobs, and updates the status of both foreground and background jobs. It ensures that the shell properly waits for child processes to finish before continuing execution.

builtins.c – Built-in Commands
The builtins.c file implements the shell’s built-in commands, which include:

Command	Description
cd	Changes the current working directory and updates $PWD.
exit	Exits the BigShell program.
export	Exports shell variables to the environment.
unset	Removes shell variables from the environment.
fg	Brings a background job to the foreground.
bg	Places a stopped background job into the background.
These commands are critical for the shell's basic functionality, enabling users to manage the shell environment, navigate the file system, and control processes.

Known Issues:
Error code printing is currently bugged.
