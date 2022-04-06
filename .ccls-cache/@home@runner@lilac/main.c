#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

static void repl() {
  char line[1024]; // 1024 char limit
  for (;;) { // loop until new line isn't available
    printf("> ");

    if (!fgets(line, sizeof(line), stdin)) { // get the line, break if not there
      printf("\n");
      break;
    }

    interpret(line); // interpret the line given
  }
}


static char* readFile(const char* path) {
  FILE* file = fopen(path, "rb");
  if (file == NULL) {
    fprintf(stderr, "Could not open file \"%s\".\n", path);
    exit(74);
  }
  fseek(file, 0L, SEEK_END);
  size_t fileSize = ftell(file);
  rewind(file);

  char* buffer = (char*)malloc(fileSize + 1);
  size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);
	if (bytesRead < fileSize) {
    fprintf(stderr, "Could not read file \"%s\".\n", path);
    exit(74);
  }
  buffer[bytesRead] = '\0';

  fclose(file);
  return buffer;
}

static void runFile(const char* path) {
	// read the file, interpret it, free the file buffer
  char* source = readFile(path);
  InterpretResult result = interpret(source);
  free(source); 

  if (result == INTERPRET_COMPILE_ERROR) exit(65);
  if (result == INTERPRET_RUNTIME_ERROR) exit(70);
}


int main(int argc, const char* argv[]) {
	initVM(); // starts a VM 
	
  if (argc == 1) {
    repl(); // no arguments -> start REPL
  } else if (argc == 2) {
    runFile(argv[1]); // otherwise run the file if given one
  } else {
    fprintf(stderr, "Usage: clox [path]\n"); // too many args? error
    exit(64);
  }

  freeVM(); // free objects

  return 0;
}