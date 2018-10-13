# Fast-Brainfuck-Interpreter
An interpreter for the brainfuck language written to be fast and minimal.
The program is written in C and it uses the `time.h` library to measure how many seconds the interpreter function takes to finish.
This program was originally written in 2015 to implement a simple genetic algorithm that writes programs in brainfuck (it's a programming language that uses single char instructions and it's turing complete).

## Compiling and usage
To compile and execute, use the commands:
```
gcc -o BFinterpreter.exe BFinterpreter.c 
./BFinterpreter.exe [FILE_TO_EXECUTE]
```
`FILE_TO_EXECUTE` must be a brainfuck program. 
Every non standard brainfuck letter will be ignored by the program (so you can just type characters in there as comments and the interpreter will not fail).

## Provided Files
`Hanoi_Tower.bf` (computes graphically the hanoi tower, code taken [here](http://www.clifford.at/bfcpu/)) and `mandelbrot_fractal.bf` (computes graphically the mandelbrot fractal, code taken [here](https://github.com/erikdubbelboer/brainfuck-jit/blob/master/mandelbrot.bf)) are brainfuck programs (just text) that are ready to execute and can be used to compare speeds with other brainfuck interpreters. 