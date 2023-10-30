#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;

void SListPushBack(SListNode** plt, SLTDataType x);
void SListPrint(SListNode* plt);
