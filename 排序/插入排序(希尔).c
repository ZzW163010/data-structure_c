#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

//void InsertSort(int* a, int n)
//{
//	for (int i = 1; i < n; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (a[i] < a[j])
//			{
//				int tmp = a[i];
//
//				for (int k = n - 1; k >= j; k--)
//				{
//					a[k + 1] = a[k];
//				}
//				a[j] = tmp;
//				for (int k = i + 1; k < n; k++)
//				{
//					a[k] = a[k + 1];
//				}
//			}
//		}
//	}
//}
void InsertSort(int* a, int n)
{
	for (int end = 0; end < n - 1; end++)
	{
		int tmp = a[end + 1];

		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
void ShellSort(int* a, int n)
{
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 2;

		for (int end = 0; end < n - gap; end++)
		{
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
int main()
{
	int a[100] = { 2, 4, 7, 8, 3, 6, 10, 11 ,1 ,0 ,0 ,11 ,10 ,9 ,8 };

	//InsertSort(a, 15);
	ShellSort(a, 15);
}