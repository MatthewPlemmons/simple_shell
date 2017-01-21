# Simple Shell

A shell application built during a project for Holberton School.  The application as written entirely in emacs and compiled on Ubuntu 14.04 LTS using `gcc 4.8.4`.

#Installation:
```bash
git clone https://github.com/MatthewPlemmons/simple_shell.git
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
./hsh
```
This should execute the shell, which will then print a command prompt and wait for user input.

#Usage
Available built-in commands:
- `help` prints list of avaialable builtin commands. 
- `cd` changes the current working directory within the shell
- `env` prints out the current shell varriables.
- `exit` exits the shell.

The shell scans PATH to find any other commands or programs installed on the system as well.
