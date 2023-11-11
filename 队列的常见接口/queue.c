#define _CRT_SECURE_NO_WARNINGS 
#include "queue.h"

void check_capacity(QU* ps) {
	assert(ps);
	if (ps->size == ps->capacity) {
		QUDataType* ptr = (QUDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(QUDataType));
		assert(ptr);
		ps->a = ptr;
		ps->capacity *= 2;
	}
}
void QUInit(QU* ps) {
	assert(ps);
	ps->a = (QUDataType*)malloc(DefineCap * sizeof(int));
	ps->size = 0;
	ps->capacity = DefineCap;
}
void Print(QU* ps) {
	assert(ps);
	QUDataType* cur = ps->a;
	int times = ps->size;
	while (times) {
		printf("%d ", *cur);
		times--;
		cur++;
	}
}
void QUInsert(QU* ps, QUDataType x) {
	check_capacity(ps);
	if (ps->size == 0) {
		ps->a[ps->size] = x;
		ps->size++;
	}
	else {
		QUDataType tail = ps->size;
		while (tail) {
			ps->a[tail] = ps->a[tail - 1];
			tail--;
		}
		ps->a[0] = x;
		ps->size++;
	}
}
void QUPop(QU* ps) {
	assert(ps);
	ps->size--;
}
QUDataType QUTop(QU* ps) {
	int cur = ps->size;
	cur--;
	return ps->a[cur];
}
QUDataType QUBottom(QU* ps) {
	return ps->a[0];
}
QUDataType QUNum(QU* ps) {
	return ps->size;
}
bool is_Empty(QU* ps) {
	if (ps->size == 0) {
		return false;
	}
	else {
		return true;
	}
}
QUDataType QUDestroy(QU* ps) {
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}