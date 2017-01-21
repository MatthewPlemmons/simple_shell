## Simple Shell

A shell application built during a project for [Holberton School][1].  The application was written entirely in emacs and compiled on Ubuntu 14.04 LTS using `gcc 4.8.4`.

[1]: https://www.holbertonschool.com/

### Installation
```
git clone https://github.com/MatthewPlemmons/simple_shell.git
cd simple_shell
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
./hsh
```
This should execute the shell, which will then print a command prompt and wait for user input.

### Usage
Available built-in commands:
- `help` prints list of avaialable builtin commands. 
- `cd` changes the current working directory within the shell
- `env` prints out the current shell varriables.
- `exit` exits the shell.

The shell scans PATH to find any other commands or programs installed on the system as well.
