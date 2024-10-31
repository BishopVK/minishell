## Grade

| **Score**           | **Description**     |
|-----------------------|---------------|
| <p align="center"><img width="200px" alt="170px" src="https://github.com/BishopVK/minishell/blob/main/img/Score_101.png"></p> | **Mandatory part + a part of the bonus part**   |

## minishell

The Minishell project involves creating a simple shell, similar to Bash, where you can learn learn about processes and file descriptors. The goal is to develop a program that can receive commands, execute them, and manage a command history, all while adhering to certain C programming standards.
Minishell has been my first programming project in C, and it has been possible thanks to the great work done by [@isainz-r](https://github.com/ines-sainz)

## Rules for the mandatory part of the project

To meet the objectives of the mandatory part of the project, the following rules must be followed:

| **#** | **Instruction**                                                                                                                                                         |
| ----- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|  `1`  | `Code Standard:` The project must be written following the Norm. Any error in additional files or functions will result in a grade of 0.                                                                                                |
|  `2`  | `Error Handling:` Functions should not terminate unexpectedly (e.g., segfault, bus error, double free), except in cases of undefined behavior. Otherwise, the project will be considered non-functional and will receive a 0.                                                                |
|  `3`  | `Memory Management:` All memory allocated on the heap must be properly freed. Memory leaks will not be permitted.                                                                                                 |
|  `4`  | `Makefile:` If required, you must provide a Makefile that compiles the source files with the flags -Wall, -Werror, and -Wextra, using cc. The Makefile should not perform relinking. |
|  `5`  | `Makefile Rules:` It should include at least the rules $(NAME), all, clean, fclean, and re.       |
|  `6`  | `Use of libft:` If the use of libft is allowed, you should copy its source files and Makefile into a libft directory with its respective Makefile. The project’s Makefile should compile the library first, then the project.                                                              |
|  `7`  | `Testing:` It is recommended to create test programs to verify that your program functions correctly, though these tests will not be submitted or evaluated.                                                                                          |
|  `8`  | `Submission:` The work must be submitted in your assigned Git repository, as only the work in the repository will be evaluated.                                                                                     |
|  `9`  | `Separate Evaluation:` The mandatory part and the bonuses will be evaluated separately.                                                                            |

## Functionalities

In the mandatory part of the Minishell project, the shell is required to implement the following functionalities:

| Functionality  | Description                         | Extra-description |
| ----- | ----------------------------------- |------------------- |
| `Command Prompt` | Display a prompt while waiting for a new command.      | |
| `Functional History` | Maintain a history of executed commands.           | |
| `Executable Search and Execution` | Search for and execute the correct executable based on the PATH variable or through relative or absolute paths.   | |
| `Signal Handling` | Avoid using more than one global variable to indicate a signal reception, meaning the signal handler should not access main data structures. | |
| `Built-in Implementation` | `echo` with the -n option. | Returns text entered by the user. The -n flag prevents a newline from being added. |
|   | `cd` with only a relative or absolute path. | Allows the user to navigate between directories. |
|   | `pwd` without options. | Allows the user to view the full path of the current directory. |
|   | `export` without options. | Allows the user to create exported environment variables, modify them, or view all existing ones with or without content. |
|  | `unset` without options. | Allows the user to delete environment variables. |
|  | `env` without options or arguments. | Allows the user to view environment variables with content. |
|  | `exit` without options. | Allows the user to terminate execution. Additionally, all options and behaviors of Bash have been added when receiving arguments. |
| `Redirection Management:` | `<` | Should redirect input. |
|  | `>` | should redirect output. |
|  | `<<` | Should accept a delimiter and read from input until a line containing only the delimiter appears (without updating the history). Additionally, the behavior of Bash has been replicated by not expanding the delimiter if it is an environment variable, while allowing the here-doc to expand the content entered by the user as long as the delimiter does not contain any quotes of any kind. |
|  | `>>` | Should redirect output in append mode. |
| `Pipe Implementation` | The output of each command in the pipeline is piped to the input of the next command. | |
| `Environment Variable Expansion` | Environment variables (preceded by $) should expand to their values as long as they are not within single quotes. | |
| `Exit Status Management` | $? should expand to the exit status of the most recent command executed in the pipeline. It should also be updated with the received signals. | |
| `Key Combination Handling` | `ctrl-C` | On a clean prompt shows a new line with a clean prompt. On a prompt with text shows a new line with a clean prompt. After executing a blocking command like cat with no arguments or grep "something" should work the same as in Bash. |
|  | `ctrl-\`                    | On a clean prompt does nothing. On a prompt with text does nothing. After executing a blocking command like cat with no arguments or grep "something" should work the same as in Bash. |
|  | `ctrl-D` | On a clean prompt terminates minishell. On a prompt with text does nothing. After executing a blocking command like cat with no arguments or grep "something" should work the same as in Bash. |
| `Quote Interpretation` | Single quotes (')                    | Should prevent the shell from interpreting metacharacters within the quoted sequence. |
|  | Double quotes (")                    | Should prevent the shell from interpreting metacharacters within the quoted sequence, except for the dollar sign ($). |
| `No Interpretation of Special Characters` | Do not interpret unclosed quotes or special characters not specified in the subject, such as \ (backslash) or ; (semicolon). | |
