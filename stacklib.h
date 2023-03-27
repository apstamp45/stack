#include <stdbool.h>

#define DEFAULT_STACK_SIZE 256

enum operation {
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	MODULUS
};

/*
 * Reallocates the stack memory
 * to the given size.
 */
int* extend_stack(int* stack, int size);

/*
 * Adds the given value num
 * to the stack.
 */
int push(int* stack, int top, int num);

/**
 * Does a math operation on the top two stack values,
 * and, if push is set to true, adds it
 * to the stack. Otherwise, it replaces the
 * values. Example: math(., ., ADD, false)
 * pops the top 2 values and pushes the second
 * value from the top divided by the first.
 * op (operation) values:
 * 0: add, 1: subtract, 2: multiply, 3: divide,
 * 4: modulo
 */
int math(int* stack, int top, enum operation op, bool push);

/*
 * Prints the stack's contents to stdout.
 */
void print_stack(int* stack, int top);
