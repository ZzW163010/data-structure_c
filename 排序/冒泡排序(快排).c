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

//三数取中

int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;
	
	if (a[left] < a[mid])
	{
		if (a[mid] <  a[right])
		{
			return mid;
		}
		else if (a[right] < a[left])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[right] > a[left])
		{
			return  left;
		}
		else
		{
			return  right;
		}
	}
}
//挖坑法
int PartSort1(int* a, int left, int right)
{

	int begin = left;
	int end = right;
	int p = begin;
	int k = a[begin];

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
	return p;
}
//左右指针法
int PartSort2(int* a, int left, int right)
{
	int begin = left;
	int end = right;
	int keyi = begin;

	while (begin < end)
	{
		while (begin < end && a[begin] <= a[keyi]) begin++;
		while (begin < end && a[end] >= a[keyi]) end--;
		Swap(&a[begin], &a[end]);
	}

	Swap(&a[begin], &a[keyi]);

	return begin;
}
//前后指针法
int PartSort3(int* a, int left, int right)
{
	int prev = left;
	int cur = prev + 1;
	int keyi = prev;

	while (cur <= right)
	{
		if (a[cur] <= a[keyi] && prev++ != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[prev], &a[keyi]);
	
	return prev;
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	//三数取中

	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);

	//单趟排序(挖坑法，左右指针，前后指针)

	int keyIndex = PartSort3(a, left, right);

	//小区间优化
	if (keyIndex - 1 - left > 10)
	{
		QuickSort(a, left, keyIndex - 1);
	}
	else
	{
		InsertSort(a + left, keyIndex - 1 - left + 1);
	}

	if (right - (keyIndex + 1) > 10)
	{
		QuickSort(a, keyIndex + 1, right);
	}
	else
	{
		InsertSort(a + keyIndex + 1, right - (keyIndex + 1) + 1);
	}

}
