#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#define DefineCap 2
typedef int QUDataType;

typedef struct QU {
	QUDataType* a;
	int size;
	int capacity;
}QU;

void QUInit(QU* ps);
void Print(QU* ps);
//插入数据
void QUInsert(QU* ps, QUDataType x);
//删除数据
void QUPop(QU* ps);
//返回队列头部数据
QUDataType QUTop(QU* ps);
//摧毁队列
QUDataType QUDestroy(QU* ps);
//返回队列尾部数据
QUDataType QUBottom(QU* ps);
//返回队列数据数量
QUDataType QUNum(QU* ps);
//判断队列是否为空
bool is_Empty(QU* ps);