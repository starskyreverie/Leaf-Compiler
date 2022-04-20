# LilacScript

An object-oriented, dynamically typed, general-purpose programming language that supports mathematical algebraic expressions (graphing expressions, integrals, derivatives), written in C. Includes a Pratt operator-precedence parser, bytecode assembler, bytecode virtual machine, bytecode disassembler, and a read-eval-print-loop. 

[Repl.it](https://replit.com/@pq43/LilacScript)

## Example LilacScript code

```
var x = sin(3.14);
print x;
```
Output: `0`

```
fun fib(n) {
	if(n < 2) return n;
	return fib(n-2) + fib(n-1);
}

print fib(30);
```
Output: `832040`

```
fun integralAndDerivativeGraph(functionToGraph, a, b) {
	graph(functionToGraph, a, b);
	graph(derivative(functionToGraph, a), a, b);
	graph(integral(functionToGraph, a, b), a, b);
}

integralAndDerivativeGraph("sin(x)", 0, 10*pi);
```

Output: A graph of `sin(x) from 0 to 10pi`, a graph of `d/dx sin(0) = cos(0) = 1 from 0 to 10pi`, and a graph of `integral(sin(x)) from 0 to 10pi = -cos(10pi)-(-cos(0)) = 0 from 0 to 10pi`  

## Instructions to run

You can either use your own Makefile or the one already here in this repo to run the program using `make -s`. After you've done that, it'll output to a file called `main`, so you can run `./main` to use the read-eval-print-loop (REPL) or `./main filename.lilac` to run a file.

## Licensing

This uses the MIT License and follows Robert Nystrom's Clox implementation from his book [Crafting Interpreters](https://craftinginterpreters.com/). It's an amazing book that has taught me most of what I know about compilers today.
