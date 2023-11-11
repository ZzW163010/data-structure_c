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
//ջ����������
void StackPushBack(SL* stack, SLDataType x);
//ջ��ɾ��ɾ������
void StackPopBack(SL* stack);
//�ݻ�ջ
void StackDestry(SL* stack);
//����ջ��������
SLDataType StackTop(SL* stack);
//�������ݸ���
int StackNum(SL* stack);
//�ж�ջ�Ƿ�Ϊ��
int Is_StackEmpty(SL* stack);


