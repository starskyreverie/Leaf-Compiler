#include <stdio.h>
#include "memory.h"
#include "value.h"

void initValueArray(ValueArray* array) {
	array->values = NULL;
	array->capacity = 0;
	array-> count = 0;
}

void writeValueArray(ValueArray* array) {
	if(array->capacity < array->count+1) {
		int oldCapacity = array->capacity;
		array->capacity = GROW_CAPACITY(oldCapacity);
		
	} 
	array->values[array->count] = value;
	array->count++;
}