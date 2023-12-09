//归并排序

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
	{
		return;
	}

	int mid = (left + right) / 2;

	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	int begin1 = left, endl = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;

	while (begin1 <= endl && begin2 <= end2)
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
	while (begin1 <= endl)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	int left = 0, right = n - 1;

	_MergeSort(a, left, right, tmp);

	free(tmp);

}

//计数排序

void CoutSort(int* a, int n)
{
	int max = a[0], min = a[0];

	for (int i = 0; i < n; i++)
	{
		if (a[i] > max) max = a[i];
		if (a[i] < min) min = a[i];
	}
	int range = max - min + 1;
	int* cnt = (int*)malloc(sizeof(int) * range);
	assert(cnt);
	memset(cnt, 0, sizeof(int) * range);
	
	for (int i = 0; i < n; i++)
	{
		cnt[a[i] - min]++;
	}
	
	int j = 0;

	for (int i = 0; i < range; i++)
	{
		while (cnt[i]--)
		{
			a[j++] = i + min;
		}
	}
	free(cnt);
}
