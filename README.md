# Fast-Brainfuck-Interpreter
An interpreter for the brainfuck language written to be as fast as possible.

The program is written in C and it uses the time.h library to measure how many seconds the interpreter function takes to finish.

## Compiling and usage
To compile and execute, use the commands:
```
gcc -o BFinterpreter.exe BFinterpreter.c 
./BFinterpreter.exe [FILE_TO_EXECUTE]
```
`FILE_TO_EXECUTE` must be a brainfuck program. 
Every non standard brainfuck letter will be ignored by the program (so you can just type characters in there as comments and the interpreter will not fail).

## Provided Files
`Hanoi_Tower.bf` (computes graphically the hanoi tower) and `mandelbrot_fractal.bf` (computes graphically the mandelbrot fractal) are brainfuck programs (just text) that are ready to execute and can be used to compare speeds with other brainfuck interpreters