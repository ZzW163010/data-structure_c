#define _CRT_SECURE_NO_WARNINGS 

#include "queue.h"

void test() {
	QU* phead = NULL;
	QUInsert(&phead, 3);
	QUInsert(&phead, 4);
	QUInsert(&phead, 5);
	QUInsert(&phead, 6);
	QUPop(&phead);
	QUPrint(phead);
}
int main()
{
	test();
	return 0;
}