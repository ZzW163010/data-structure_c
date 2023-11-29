void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 1;  
		 
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}

void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 1;  
		 
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}

void QuickSort(int* a, int left, int right)
{
	int begin = left;
	int end = right;
	int p = begin;
	int k = a[begin];
	
	if (left >= right)
	{
		return;
	}
	else
	{
		while (begin < end)
		{
			while (begin < end && a[end] >= k)
			{
				end--;
			}
			a[p] = a[end];
			p = end;
			while (begin < end && a[begin] <= a[p])
			{
				begin++;
			}
			a[p] = a[begin];
			p = begin;
		}
		a[p] = k;
	}
	QuickSort(a, left, p - 1);
	QuickSort(a, p + 1, right);
}
