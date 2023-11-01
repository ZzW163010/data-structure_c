#define _CRT_SECURE_NO_WARNINGS 
#include "List.h"

void ListPint(ListNode* phead)
{
	ListNode* cur = phead;

	while (cur != phead->prev)
	{
		cur = cur->next;
		printf("%d->", cur->data);
	}
	printf("%d", phead->data);
}
ListNode* OcurNewNode(LTDataType x)
{
	ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
	
	NewNode->data = x;
	NewNode->next = NULL;
	NewNode->prev = NULL;

	return NewNode;
}
ListNode* ListInit()
{
	ListNode* phead = OcurNewNode(0);
	phead->next = phead;
	phead->prev = phead;
	
	return phead;
}
void ListPushBack(ListNode* phead, LTDataType x)
{
	ListNode* NewNode = OcurNewNode(x);
	if (NewNode == NULL)
	{
		perror("List.c:33:");
		return;
	}
	else
	{
		phead->prev->next = NewNode;
		NewNode->prev = phead->prev;
		NewNode->next = phead;
		phead->prev = NewNode;
	}
}