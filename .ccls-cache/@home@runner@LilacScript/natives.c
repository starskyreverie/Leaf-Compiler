#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "natives.h"
#include "object.h"
#include "util.h"
#include "vm.h"

static Value clockNative(int argCount, Value* args) {
    return NUMBER_VAL((double)clock() / CLOCKS_PER_SEC);
}

static Value timeNative(int argCount, Value* args) {
    return NUMBER_VAL((double)time(NULL));
}

static Value sinFunction(int argCount, Value* args) {
  if (argCount != 1) {
      runtimeError("sin() takes exactly 1 argument (%d given).", argCount);
      return NIL_VAL;
  }

	if(!IS_NUMBER(args[0])) {
		runtimeError("The argument passed to sin() must be a number.", argCount);
		return NIL_VAL;
	}
	
	return NUMBER_VAL((double)(sin(args[0])));
}
		
static Value cosFunction(int argCount, Value* args) {
  if (argCount != 1) {
      runtimeError("cos() takes exactly 1 argument (%d given).", argCount);
      return NIL_VAL;
  }

	if(!IS_NUMBER(args[0])) {
		runtimeError("The argument passed to cos() must be a number.", argCount);
		return NIL_VAL;
	}
	
	return NUMBER_VAL((double)(cos(args[0])));
}

static Value tanFunction(int argCount, Value* args) {
  if (argCount != 1) {
      runtimeError("tan() takes exactly 1 argument (%d given).", argCount);
      return NIL_VAL;
  }

	if(!IS_NUMBER(args[0])) {
		runtimeError("The argument passed to tan() must be a number.", argCount);
		return NIL_VAL;
	}
	
	return NUMBER_VAL((double)(tan(args[0])));
}
static Value strNative(int argCount, Value* args) {
    if (argCount != 1) {
        runtimeError("str() takes exactly 1 argument (%d given).", argCount);
        return NIL_VAL;
    }

    if (!IS_STRING(args[0])) {
        char* valueString = valueToString(args[0]);

        ObjString* string = copyString(valueString, strlen(valueString));
        free(valueString);

        return OBJ_VAL(string);
    }

    return args[0];
}

static Value boolNative(int argCount, Value* args) {
    if (argCount != 1) {
        runtimeError("bool() takes exactly 1 argument (%d given).", argCount);
        return NIL_VAL;
    }

    return BOOL_VAL(!isFalsey(args[0]));
}

static Value lenNative(int argCount, Value* args) {
    if (argCount != 1) {
        runtimeError("len() takes exactly 1 argument (%d given).", argCount);
        return NIL_VAL;
    }

    if (IS_STRING(args[0]))
        return NUMBER_VAL(AS_STRING(args[0])->length);

    runtimeError("Unsupported type passed to len()", argCount);
    return NIL_VAL;
}


float BooleRule(float (*y)(int), float a, float b)
{
    // Number of intervals
 
    int n = 4;
    int h;
 
    // Computing the step size
    h = ((b - a) / n);
    float sum = 0;
 
    // Substituing a = 0, b = 4 and h = 1
    float bl = (7 * y(a) + 32 * y(a + h)
                + 12 * y(a + 2 * h)
                + 32 * y(a + 3 * h)
                + 7 * y(a + 4 * h))
               * 2 * h / 45;
 
    sum = sum + bl;
    return sum;
}


static Value integralNative(int argCount, Value* args) {
	runtimeError("Function is not a valid function.", argCount);
	return NIL_VAL;
}

static Value derivativeNative(int argCount, Value* args) {
	runtimeError("Function is not a valid function.", argCount);
	return NIL_VAL;
}

static Value graphNative(int argCount, Value* args) {
	runtimeError("Function is not a valid function.", argCount);
	return NIL_VAL;
}

const char* nativeNames[] = {
    "clock", "time", "str", "bool", "len", "sin", "cos", "tan", "derivative", "integral", "graph"
};

NativeFn nativeFunctions[] = {
    clockNative, timeNative, strNative, boolNative, lenNative, sinFunction, cosFunction, tanFunction, derivativeNative, integralNative, graphNative
};

static bool printNative(int argCount, Value* args) {
    if (argCount == 0) {
        printf("\n");
        return true;
    }

    for (int i = 0; i < argCount; ++i) {
        Value value = args[i];
        printValue(value);
        printf("\n");
    }

    return true;
}

static bool exitNative(int argCount, Value* args) {
    if (argCount != 1) {
        runtimeError("input() takes exactly 1 argument (%d given).", argCount);
        return true;
    }

    Value exitCode = args[0];
    if (!IS_NUMBER(exitCode)) {
        runtimeError("exit() takes only a number value.");
        return true;
    }

    exit((int)AS_NUMBER(exitCode));
}

const char* nativeVoidNames[] = {
    "print",
    "exit",
};

NativeFnVoid nativeVoidFunctions[] = {
    printNative,
    exitNative,
};

void defineAllNatives() {
    for (uint8_t i = 0; i < sizeof(nativeNames) / sizeof(nativeNames[0]); ++i)
        defineNative(nativeNames[i], nativeFunctions[i]);

    for (uint8_t i = 0;
         i < sizeof(nativeVoidNames) / sizeof(nativeVoidNames[0]);
         ++i)
        defineNativeVoid(nativeVoidNames[i], nativeVoidFunctions[i]);
}