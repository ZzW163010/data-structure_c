#define _CRT_SECURE_NO_WARNINGS 
#include "queue.h"

QU* get_newnode(QUDataType x) {
	QU* newnode = (QU*)malloc(sizeof(QU));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}
//void QUInit(QU* phead) {
//	assert(phead);
//	phead->data = 0;
//	phead->next = NULL;
//}
void QUPrint(QU* phead) {
	assert(phead);
	QU* cur = phead;
	while (cur != NULL) {
		printf(type, cur->data);
		cur = cur->next;
	}
}
void QUInsert(QU** phead, QUDataType x) {
	assert(phead);
	QU* newnode = get_newnode(x);
	QU* tail = *phead;
	if (*phead == NULL) {
		*phead = newnode;
	}
	else {

		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newnode;
	}
	//此处可用尾指针优化(在外面定义一个尾指针)
}
void QUPop(QU** phead) {
	
	assert(*phead);
	QU* tmp = (*phead)->next;
	free(*phead);
	*phead = tmp;
}