# ACoolCompilerName

A compiler for an object-oriented, dynamically typed, general-purpose programming language that supports mathematical algebraic expressions (graphing expressions, integrals, derivatives), written in C. Includes a Pratt operator-precedence parser, bytecode assembler, bytecode virtual machine, bytecode disassembler, and a read-eval-print-loop. 

[Repl.it](https://replit.com/@pq43/ACoolCompilerName)

## Example code

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

## Instructions to run

You can either use your own Makefile or the one already here in this repo to run the program using `make -s`. After you've done that, it'll output to a file called `main`, so you can run `./main` to use the read-eval-print-loop (REPL) or `./main filename.lilac` to run a file.

## Licensing

This uses the MIT License and follows Robert Nystrom's Clox implementation from his book [Crafting Interpreters](https://craftinginterpreters.com/). It's an amazing book that has taught me most of what I know about compilers today, and if you haven't read it I really recommend it!
