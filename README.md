#Simple Shell
## This project is about creating a simple version of shell.


## 📜 Introduction
- What is Shell?

  Shell is an enviorment in which we can run our commands, programs and shell scripts.

- What is the difference between a function & a system call?

  The main difference between system call and function call is that a system call is a request for the kernel to access a resource while a function call is a request made by a program to perform a specific task. System call are used when a program needs to communicate with the kernel while function call are to call a specific function within the program.

- How does the shell use the PATH to find the programs?

  The PATH variable is basically a list of directories your computer looks through to fing a requested executable.

- How to suspend the execution of a process until one of its children terminates?

  We can suspend the execution of a process until one of its children terminates using the wait function. A call to wait() blocks the calling process until one of its child processes exits or a signal is received. After child process terminates, parent continues its execution after wait system call instruction.


## 🎯 Tasks

  * Task 0 - Write a README, Write a man for your shell & AUTHOR file.

  * Task 1 - Write a beautiful code that passed the Betty checks

  * Task 2
     Write a UNIX command line interpreter.


Your Shell should:

   Display a prompt and wait for the user to type a command. A command line always ends with a new line.
   The prompt is displayed again each time a command has been executed.
   The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
   The command lines are made only of one word. No arguments will be passed to programs.
   If an executable cannot be found, print an error message and display the prompt again.
   Handle errors.
   You have to handle the “end of file” condition (Ctrl+D)

You don’t have to:

   use the PATH
   implement built-ins
   handle special characters
   be able to move the cursor
   handle commands with arguments

  * Task 3 - Handle command lines with arguments

  * Task 4 - Handle the PATH, fork must not be called if the command doesnt exist

  * Task 5 - Implement the exit built-in, that exits the shell

  * Task 6 - Implement the env built-in, that prints the current enviorment

##Language: ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)


## Developers
[Luis Ayala](https://github.com/luisayala323) & [Yaniel Ramos](https://github.com/YanielRamos)
