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
void SListPushFront(SListNode** plt, SLTDataType x);
void SListPopBack(SListNode** plt);
void SListPopFront(SListNode** plt);
SListNode* SListFind(SListNode* plt, SLTDataType x);
void SListInsert(SListNode** plt, SListNode* adr, SLTDataType x);
void SListErase(SListNode** plt, SListNode* adr);
