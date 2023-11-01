#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

ListNode* ListInit();
void ListPushBack(ListNode* phead, LTDataType x);
void ListPint(ListNode* phead);
