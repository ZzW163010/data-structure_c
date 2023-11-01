#define _CRT_SECURE_NO_WARNINGS 
#include "SList.h"

void SListPrint(SListNode* plt)
{
	SListNode*cur = plt;

	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}
SListNode* BuySListNode(x)
{
	SListNode* NewNode = (SListNode*)malloc(sizeof(SListNode));

	if (NewNode == NULL)
	{
		perror("SList.c:20:");
	}
	else
	{
		NewNode->data = x;
		NewNode->next = NULL;
	}
	return NewNode;
}
SListNode* SListFind(SListNode* plt, SLTDataType x)
{
	SListNode* cur = plt;
	
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void SListPushBack(SListNode** plt, SLTDataType x)
{
	SListNode*NewNode = BuySListNode(x);

	if (*plt == NULL)
	{
		*plt = NewNode;
	}
	else
	{
		SListNode* tail = *plt;

		while (tail->next != NULL)
		{
			tail = tail->next;
		}
			tail->next = NewNode;
	}
}
	/*SListNode** tail = plt;
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
	}*/
	
void SListPushFront(SListNode** plt, SLTDataType x)
{
	SListNode* NewNode = BuySListNode(x);

	NewNode->next = *plt;
	*plt = NewNode;
}
void SListPopBack(SListNode** plt)
{
	SListNode*tail = *plt;
	if (tail == NULL)
	{
		printf("没有可删除的链表\n");
	}
	else if (tail->next == NULL)
	{
		free(*plt);
		*plt = NULL;
	}
	SListNode* prev = NULL;
	while (tail->next != NULL)
	{
		prev = tail;
		tail = tail->next;
	}
	free(tail);
	prev->next = NULL;
}
void SListPopFront(SListNode** plt)
{
	if (*plt == NULL)
	{
		printf("没有可删的链表\n");
	}
	SListNode* next = (*plt)->next;
	free(*plt);
	*plt = next;
}
void SListInsert(SListNode** plt, SListNode* adr, SLTDataType x)
{
	SListNode* NewNode = BuySListNode(x);

	if (*plt == NULL)
	{
		*plt = NewNode;
	}
	else if (adr == *plt)
	{
		SListPushFront(plt, x);
		//NewNode->next = *plt;
		//*plt = NewNode;
	}
	else
	{
		SListNode* tail = *plt;
		SListNode* prev = NULL;

		while (tail != adr)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = NewNode;
		NewNode->next = adr;
	}
}
void SListErase(SListNode** plt, SListNode* adr)
{
	
	if (*plt == NULL)
	{
		printf("没有可删的链表\n");
	}
	else if (adr == *plt)
	{
		SListPopFront(plt);
	}
	else 
	{
		SListNode* prev = *plt;

		while (prev->next != adr)
		{
			prev = prev->next;
		}
		
		prev->next = adr->next;
		free(adr);
		adr == NULL;
	}
}
