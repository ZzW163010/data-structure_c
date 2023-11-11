#define _CRT_SECURE_NO_WARNINGS 
#include "queue.h"



void test() {
	QU a;
	QUInit(&a);
	QUInsert(&a, 5);
	QUInsert(&a, 6);
	QUInsert(&a, 7);
	QUInsert(&a, 8);
	QUInsert(&a, 9);
	QUPop(&a);
	QUDataType ret = QUNum(&a);
	printf("%d\n", ret);
	Print(&a);
}
int main() {
	test();
}
