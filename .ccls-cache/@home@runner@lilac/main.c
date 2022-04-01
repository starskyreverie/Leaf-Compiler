#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char* argv[]) {
	Chunk chunk;
	printf("%p\n", &chunk);
	Chunk *ptr = &chunk;
	printf("%p\n", ptr);
	initChunk(&chunk);
	writeChunk(&chunk, OP_RETURN);
	writeChunk(&chunk, 4);
	disassembleChunk(&chunk, "test chunk");
	freeChunk(&chunk);
  return 0;
}