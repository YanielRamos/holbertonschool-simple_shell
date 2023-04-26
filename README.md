# #cisfun$
![alt text](https://i.pinimg.com/originals/31/03/c8/3103c8eebafd5581ad744bc3ce68b4d5.gif)


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



### Allowed functions & system calls

    - access (man 2 access)
    - chdir (man 2 chdir)
    - close (man 2 close)
    - closedir (man 3 closedir)
    - execve (man 2 execve)
    - exit (man 3 exit)
    - _exit (man 2 _exit)
    - fflush (man 3 fflush)
    - fork (man 2 fork)
    - free (man 3 free)
    - getcwd (man 3 getcwd)
    - getline (man 3 getline)
    - getpid (man 2 getpid)
    - isatty (man 3 isatty)
    - kill (man 2 kill)
    - malloc (man 3 malloc)
    - open (man 2 open)
    - opendir (man 3 opendir)
    - perror (man 3 perror)
    - read (man 2 read)
    - readdir (man 3 readdir)
    - signal (man 2 signal)
    - stat (__xstat) (man 2 stat)
    - lstat (__lxstat) (man 2 lstat)
    - fstat (__fxstat) (man 2 fstat)
    - strtok (man 3 strtok)
    - wait (man 2 wait)
    - waitpid (man 2 waitpid)
    - wait3 (man 2 wait3)
    - wait4 (man 2 wait4)
    - write (man 2 write)

### 🌴Enviroments
    - Language: C
    - Compiler: gcc
    - OS: Ubuntu 20.04
    - Style guideines: Betty Style

## 👨🏾‍💻Developers
[Luis Ayala](https://github.com/luisayala323) & [Yaniel Ramos](https://github.com/YanielRamos)



[Back to Top](# #cisfun$)
