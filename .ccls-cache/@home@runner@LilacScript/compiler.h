#ifndef clox_compiler_h
#define clox_compiler_h

#include "object.h"
#include "vm.h"

//< Compiling Expressions compile-h
/* Scanning on Demand compiler-h < Compiling Expressions compile-h
void compile(const char* source);
*/
/* Compiling Expressions compile-h < Calls and Functions compile-h
bool compile(const char* source, Chunk* chunk);
*/
//> Calls and Functions compile-h
ObjFunction* compile(const char* source);
//< Calls and Functions compile-h
//> Garbage Collection mark-compiler-roots-h
void markCompilerRoots();
//< Garbage Collection mark-compiler-roots-h

#endif