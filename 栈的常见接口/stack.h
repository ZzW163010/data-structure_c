#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define DefineNum 2

typedef int SLDataType;

typedef struct Stack {
	SLDataType* a;
	int top;
	int capicity;
}SL;

void StackInit(SL* stack);
void StackPrint(SL* stack);
//栈顶插入数据
void StackPushBack(SL* stack, SLDataType x);
//栈顶删除删除数据
void StackPopBack(SL* stack);
//摧毁栈
void StackDestry(SL* stack);
//返回栈顶的数据
SLDataType StackTop(SL* stack);
//返回数据个数
int StackNum(SL* stack);
//判读栈是否为空
int Is_StackEmpty(SL* stack);


