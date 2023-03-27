#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stacklib.h"

int main(int argc, char* argv[]) {
	char* program;
	int* stack;
	int stacksize = DEFAULT_STACK_SIZE;
	int top = -1;
	stack = malloc(stacksize * sizeof(int));
	if (argc < 2) {
		fprintf(stderr, "Program string must be provided.\n");
		return 1;
	} else {
		program = argv[1];
	}
	int i = 0;
	char c = program[i];
	while (c != 0) {
		if (isdigit(c)) {
			int num = c - 48;
			c = program[++i];
			while (isdigit(c)) {
				num = 10 * num + c - 48;
				c = program[++i];
			}
			top = push(stack, top, num);
			continue;
		} else if (strchr("+-*/%", c)) {
			bool push = false;
			int op;
			if (program[i + 1] == c) {
				push = true;
			}
			switch (c) {
				case '+':
					op = ADD;
					break;
				case '-':
					op = SUBTRACT;
					break;
				case '*':
					op = MULTIPLY;
					break;
				case '/':
					op = DIVIDE;
					break;
				default:
					op = MODULUS;
			}
			top = math(stack, top, op, push);
			if (push) {
				i++;
			}
		}
		if (top >= stacksize) {
			stack = extend_stack(stack, stacksize + DEFAULT_STACK_SIZE);
		}
		c = program[++i];
	}
	print_stack(stack, top);
	free(stack);
}
