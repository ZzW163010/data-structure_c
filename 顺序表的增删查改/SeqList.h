#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#define DENUMS 2
typedef int SQdataType;

typedef struct SeqList
{
	SQdataType *ar;
	int size;
	int capacity;
}SL;

 void SeqListInit(SL* seq);
 void SeqListPrint(SL* seq);
 void SeqListPushBack(SL* seq, SQdataType x);
 void SeqListPushFront(SL* seq, SQdataType x);
 void SeqListPopBack(SL* seq);
 void SeqListPopFront(SL* seq);
 void SeqListInsert(SL* seq, SQdataType x);
 void SeqListModify(SL* seq, SQdataType x);
 void SeqListSort(SL* seq);

