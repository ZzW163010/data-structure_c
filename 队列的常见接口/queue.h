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
//��������
void QUInsert(QU* ps, QUDataType x);
//ɾ������
void QUPop(QU* ps);
//���ض���ͷ������
QUDataType QUTop(QU* ps);
//�ݻٶ���
QUDataType QUDestroy(QU* ps);
//���ض���β������
QUDataType QUBottom(QU* ps);
//���ض�����������
QUDataType QUNum(QU* ps);
//�ж϶����Ƿ�Ϊ��
bool is_Empty(QU* ps);