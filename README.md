# Simple Shell (Holberton School) 

This repository contains the source code for the **Holberton Simple Shell** project, which is a shell-like program written in C. The goal of this project is to help students understand how a shell works and to learn about the environment, functions, system calls, and process creation using `execve`.

## Getting Started

To get started with this project, you can clone this repository using the following command:
```
git clone https://github.com/Theemiss/simple_shell.git
```
Once you have cloned the repository, you can compile the program using the following command:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
You can then run the program by invoking `./hsh` in the same directory.

## Usage

The Holberton Simple Shell program can handle two types of commands: built-ins and normal programs. Here is a list of built-in commands currently supported by the program:

* `cd [directory]`: Switch to the specified directory (path).
* `env`: Displays the environment variable.
* `exit [exitstatus]`: Exit from the program with exitstatus value. 0 by default.
* `getenv NAME`: Return the value of the NAME variable if it is in the environment.
* `help [command]`: Displays the syntax for the command, or all commands.
* `history`: Displays the last typed user.
* `echo [$$]` or `[$?]` or `[$PATH]`: Return pid and exit statue and PATH.
* Command Basicly Every Program in `$PATH`: It Support Single Word like `ls`. It Handle Path `ls /tmp` and Options Like `ls -l`.

## More Info

See the `man_1_simple_shell` man page to get info about syntax, sipnosis, etc.

## Credits

Shell made by [@Ferlandoo](https://www.github.com/Ferlandoo), [@EderHodaj](https://github.com/EderHodaj) and [@FloriMecaj](https://github.com/FloriMecaj).
