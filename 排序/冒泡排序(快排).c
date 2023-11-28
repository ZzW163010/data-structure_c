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

//挖坑法
void privot(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	int p = 0;
	int k = a[0];

	while (begin < end)
	{
		while (begin < end && a[end] >= k)
		{
			end--;
		}
		a[p] = a[end];
		p = end;
		
		while (begin < end && a[begin] <= k)
		{
			begin++;
		}
		a[p] = a[begin];
		p = begin;
	}
	a[p] = k;
}
