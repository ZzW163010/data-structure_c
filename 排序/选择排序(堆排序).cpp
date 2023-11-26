void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//遍历选一次

//void SelectSort(int* a, int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		int m = i;
//
//		for (int j = i; j < n; j++)
//		{
//			if (a[j] < a[m])
//			{
//				m = j;
//			}
//		}
//		Swap(&a[i], &a[m]);
//	 }
//}

//遍历选两次

void SelectSort(int* a, int n)
{
	int end = n - 1;
	int begin = 0;

	while (begin < end)
	{
		int mi = begin, mx = end;

		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[mi])
			{
				mi = i;
			}
			else if(a[i] > a[mx])
			{
				mx = i;
			}
		}
		Swap(&a[begin], &a[mi]);
		Swap(&a[end], &a[mx]);
		end--;
		begin++;
	}
}

//向下调整算法

void AdjustDown(int* a, int n, int root)
{
	int child = root * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[root])
		{
			Swap(&a[child], &a[root]);
		}
		root = child;
		child = 2 * root + 1;
	}
	
}

//升序应建大堆，建小堆即第二个做根节点，顺序就会全乱

void HeapSort(int* a, int n)
{
	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	//排序
	int end = n - 1;

	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		end--;
		AdjustDown(a, end, 0);
	}
}
