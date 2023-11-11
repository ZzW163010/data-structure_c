#define _CRT_SECURE_NO_WARNINGS 
#include "stack.h"

void test_capacity(SL* stack) {
	assert(stack);
	if (stack->top == stack->capicity) {
		SLDataType* prt = realloc(stack->a, 2 * stack->capicity * sizeof(SLDataType));
		assert(prt);
		stack->a = prt;
		stack->capicity *= 2;
	}
}
//SLDataType* get_newpin() {
//	SLDataType* newpin = (SLDataType*)malloc(sizeof(SLDataType));
//	assert(newpin);
//	return newpin;
//}

void StackInit(SL* stack) {
	assert(stack);
	stack->a = (SLDataType*)malloc(DefineNum * sizeof(SLDataType));
	stack->top = 0;
	stack->capicity = DefineNum;
}
void StackPushBack(SL* stack, SLDataType x) {
	
	assert(stack);
	test_capacity(stack);
	//SLDataType* newpin = get_newpin();
	//assert(newpin);
	//stack->a = newpin;
	stack->a[stack->top] = x;
	stack->top++;
}
void StackPrint(SL* stack) {
	SLDataType * cur = stack->a;
	SLDataType* tims = stack->top;
	while (tims) {
		printf("%d ", *cur);
		tims--;
		cur++;
	}
}
void StackPopBack(SL* stack){
	assert(stack);
	assert(stack->top > 0);
	stack->top--;
}
void StackDestry(SL* stack) {
	assert(stack);
	free(stack->a);
	stack->capicity = 0;
	stack->top = 0;
	stack->a = NULL;
}
SLDataType StackTop(SL* stack) {
	assert(stack);
	assert(stack->top > 0);
	return stack->a[stack->top - 1];
}
int StackNum(SL* stack)
{
	assert(stack);
	return stack->top;
}
int Is_StackEmpty(SL* stack) {
	assert(stack);
	if (stack->top) {
		return stack->top;
	}
	else {
		return 0;
	}
}