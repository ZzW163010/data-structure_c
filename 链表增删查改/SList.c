#define _CRT_SECURE_NO_WARNINGS 
#include "SList.h"

void SListPrint(SListNode* plt)
{
	SListNode* cur = plt;

	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}
void SListPushBack(SListNode** plt, SLTDataType x)
{
	SListNode** tail = plt;

	if (*tail == NULL)
	{
		*tail = (SListNode*)malloc(sizeof(SListNode));
		if (*tail == NULL)
		{
			perror("SList:23:");
			return;
		}
		else
		{
			(*tail)->data = x;
			(*tail)->next = NULL;
		}
	}
	else
	{
		while ((*tail)->next != NULL)
		{
			*tail = (*tail)->next;
		}

		(*tail)->next = (SListNode*)malloc(sizeof(SListNode));

		if ((*tail)->next == NULL)
		{
			perror("test.c:10:");
			return;
		}
		else
		{
			(*tail)->next->data = x;
			(*tail)->next->next = NULL;
		}
	}
	
}
