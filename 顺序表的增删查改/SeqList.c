#define _CRT_SECURE_NO_WARNINGS 
#include"SeqList.h"

void SeqListInit(SL* seq)
{
	seq->ar = malloc(DENUMS * sizeof(SQdataType));
	if (seq->ar == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	memset(seq->ar, 0, sizeof(SQdataType) * DENUMS);
	seq->size = 0;
	seq->capacity = DENUMS;
}

void SeqListPrint(SL* seq)
{
	int i = 0;
	for (i = 0; i < seq->size; i++)
	{
		printf("%d ", seq->ar[i]);
	}
	printf("\n");
}

void Excapacity(SL* seq)
{
	if (seq->size == seq->capacity)
	{
		SQdataType* ptr = (SQdataType*)realloc(seq->ar, (seq->capacity + 2) * sizeof(SQdataType));
		if (ptr == NULL)
		{
			printf("%s\n", strerror(errno));
			return;
		}
		else
		{
			seq->ar = ptr;
			seq->capacity += 2;
		}
	}
}
void SeqListPushBack(SL* seq, SQdataType x)
{
	Excapacity(seq);
	seq->ar[seq->size] = x;
	seq->size++;
}
void SeqListPushFront(SL* seq, SQdataType x)
{
	if (seq->size == 0)
	{
		seq->ar[seq->size] = x;
		seq->size++;
	}
	else
	{
		Excapacity(seq);
		int end = seq->size - 1;
		while (end >= 0)
		{
			seq->ar[end + 1] = seq->ar[end];
			end--;
		}
		seq->ar[0] = x;
		seq->size++;
	}
}
void SeqListPopBack(SL* seq)
{
	if (seq->size == 0)
	{
		printf("没有可删除的数据\n");
	}
	else
	{
		seq->size--;
	}
}
void SeqListPopFront(SL* seq)
{
	if (seq->size == 0)
	{
		printf("没有可删除的数据\n");
	}
	else
	{
		int i = 1;
		int end = seq->size - 1;
		for (i = 0; i < end ; i++)
		{
			seq->ar[i] = seq->ar[i + 1];
		}
		seq->size--;
	}
}
void SeqListInsert(SL* seq, SQdataType x)
{
	int i = 0;
	for (i = 0; i < seq->size; i++)
	{
		if (seq->ar[i] == x)
		{
			printf("找到了下标为%d\n", i);
			break;
		}
	}
	if (i == seq->size)
	{
		printf("未找到该数据\n");
	}
}
void SeqListModify(SL* seq, SQdataType x)
{
	int i = 0;
	int change = 0;
	for (i = 0; i < seq->size; i++)
	{
		if (seq->ar[i] == x)
		{
			break;
		}
	}
	printf("请输入你要更改的值>>>");
	scanf("%d", &change);
	seq->ar[i] = change;
}
void SeqListSort(SL* seq)
{
	int i = 0;
	for (i = 0; i < seq->size - 1; i++)
	{
		int j = 0;
		int flag = 0;
		int tmp = 0;
		for (j = 0; j < seq->size - 1 - i; j++)
		{
		
			if (seq->ar[j] > seq->ar[j + 1])
			{
				tmp = seq->ar[j];
				seq->ar[j] = seq->ar[j + 1];
				seq->ar[j + 1] = tmp;
				flag = 1;
			}
		}
		if (!flag)
		{
			break;
		}
	}
}