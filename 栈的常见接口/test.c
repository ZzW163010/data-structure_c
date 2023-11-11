#define _CRT_SECURE_NO_WARNINGS 
#include "stack.h"

test() {
	SL stack;
	StackInit(&stack);
	StackPushBack(&stack, 3);
	StackPushBack(&stack, 4);
	StackPushBack(&stack, 5);
	StackPushBack(&stack, 6);
	StackPopBack(&stack);
	SLDataType ret1 = StackTop(&stack);
	int ret2 = StackNum(&stack);
	printf("%d %d\n", ret1, ret2);
	StackPrint(&stack);
}
int main() {
	test();
}
