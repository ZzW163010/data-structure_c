#define _CRT_SECURE_NO_WARNINGS 
#include "List.h"

void test1()
{
	ListNode* phead = ListInit();
	ListPushBack(phead, 5);
	ListPushBack(phead, 6);
	ListPushBack(phead, 7);
	ListPint(phead);
}

int main()
{
	test1();
}