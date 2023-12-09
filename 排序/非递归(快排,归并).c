//归并排序

//对有序的两个数组进行排序

void MergeArr(int* a, int n, int begin1, int end1, int begin2, int end2, int* tmp)
{
	int begin = begin1;		//保存两个区间的开始
	int end = end2;			//保存两个区间的结束
	int i = begin1;			//与区间同步

	if (begin2 < n && end2 >= n)	//若右区间左边界在数组范围内，但右边界超出范围，
	{								//则修改右边界为n-1，在对其进行排序
		end = n - 1;
		end2 = n - 1;
	}
	if (begin2 < n && end2 < n)	//若右区间完全不在范围内,则不做处理，因为此时肯定有序
	{
		while (begin1 <= end1 && begin2 <= end2)
		{
			if (a[begin1] < a[begin2])
			{
				tmp[i++] = a[begin1++];
			}
			else
			{
				tmp[i++] = a[begin2++];
			}
		}
		while (begin1 <= end1)
		{
			tmp[i++] = a[begin1++];
		}
		while (begin2 <= end2)
		{
			tmp[i++] = a[begin2++];
		}
		//将排好的数据拷回去

		for (int i = begin; i <= end2; i++)	//归并一次返回一次，而不是一趟排完后返回
		{									//会导致塑随机数进入排序数组
			a[i] = tmp[i];
		}
	}
}

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	int gap = 1;

	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			MergeArr(a, n, i, i + gap - 1, i + gap, i + 2 * gap - 1, tmp);
		}
		gap *= 2;
	}

	//动态开辟的内存一定要记得释放

	free(tmp);
}

//快速排序

//递归的缺陷：栈帧的深度太深，栈的空间不够用，可能会溢出
//非递归
//递归该非递归：1、直接改循环(简单的递归) 2、借助数据结构栈模拟递归过程(复杂的递归)


//如何模拟递归过程: 用栈存每次单趟排的区间

//模拟栈的基本方法：将左右区间入栈。若先排左边，每次先将分出的右区间先入栈，左区间后入栈
//开始现将要排的整个数组的左右区间值入栈，当栈不为空的时候出栈得到左右区间的值，对该区间进行
//单趟排序。若分出的区间存在则每次入栈，当栈为空的时候完成排序

//注意点：区间不存在则不入栈。 
void QuickSortNonR(int* a, int n)
{
	ST st;
	StackInit(&st);
	StackPush(&st, n - 1);
	StackPush(&st, 0);

	while (!StackEmpty(&st))
	{	
		int left = StackTop(&st);
		StackPop(&st); 

		int right = StackTop(&st);
		StackPop(&st);

		int keyIndex = PartSort1(a, left, right);
		
		//区间存在入栈

		if (keyIndex + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, keyIndex + 1);
		}
		if (keyIndex - 1 > left)
		{
			StackPush(&st, keyIndex - 1);
			StackPush(&st, left);
		}
	}
	StackDestory(&st);
}
