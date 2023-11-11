#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define type "%d "
typedef int QUDataType;

typedef struct QU {
	QUDataType data;
	struct QU* next;
}QU;


//void QUInit(QU* phead);
void QUPrint(QU* phead);
void QUInsert(QU** phead, QUDataType x);
void QUPop(QU** phead);