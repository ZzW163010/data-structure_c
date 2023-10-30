#define _CRT_SECURE_NO_WARNINGS 
#include "SList.h"

void TestSList1()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 5);
	SListPushBack(&plist, 8);
	SListPrint(plist);
}
int main()
{
	
	TestSList1();
	
	return 0;
}
