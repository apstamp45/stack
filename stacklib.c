#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stacklib.h"

int* extend_stack(int* stack, int size) {
	stack = realloc(stack, size * sizeof(int));
	return stack;
}

int push(int* stack, int top, int num) {
    stack[++top] = num;
    return top;
}

int math(int* stack, int top, enum operation op, bool push) {
	if (top < 1) {
		return top;
	}
	int a = stack[top - 1];
	int b = stack[top];
	int res;
	switch (op) {
		case ADD:
			res = a + b;
			break;
		case SUBTRACT:
			res = a - b;
			break;
		case MULTIPLY:
			res = a * b;
			break;
		case DIVIDE:
			res = a / b;
			break;
		case MODULUS:
			res = a % b;
			break;
	}
	if (push) {
	    top++;
	    stack[top] = res;
	} else {
	    top--;
	    stack[top] = res;
	}
	return top;
}

void print_stack(int* stack, int top) {
	for (int i = 0; i <= top; i++) {
	    printf("%d\n", stack[i]);
	}
}
