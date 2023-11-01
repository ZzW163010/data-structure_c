#define _CRT_SECURE_NO_WARNINGS 
#include "SList.h"


void TestSList1()
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 9);
	SListPushFront(&plist, 9);
	SListPushBack(&plist, 5);
	SListPushBack(&plist, 8);
	//SListInsertFront(&plist, 2, 6);
	SListPopBack(&plist);
	//SListPopFront(&plist);
	//SListEraseFront(&plist, 2);
	SListPrint(plist);
}
void TestSList2()
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 9);
	SListPushBack(&plist, 5);
	SListPushBack(&plist, 7);

	SListNode* pos = SListFind(plist, 7);
	if (pos != NULL) 
	{
		SListInsert(&plist, pos, 6);
	}
	else
	{
		perror("test.c:33:");
		return;
	}
	if (pos != NULL)
	{
		SListErase(&plist, pos);
	}
	else
	{
		perror("test.c:33:");
		return;
	}
	//SListPopBack(&plist);
	//SListPopFront(&plist);
	//SListEraseFront(&plist, 2);
	SListPrint(plist);
}
int main()
{
	//TestSList1();
	TestSList2();

	return 0;
}
