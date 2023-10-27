#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

//int main()
//{
//    int ar[3] = { 3,0,1 };
//    int i = 0;
//
//    for (i = 0; i < 4; i++)
//    {
//        int left = 0;
//        int right = 2;
//
//        while (left < right)
//        {
//            int mid = (left + right) / 2;
//            if (ar[mid] > i)
//            {
//                right = mid - 1;
//            }
//            else if (ar[mid] < i)
//            {
//                left = mid + 1;
//            }
//            else
//            {
//                break;
//            }
//        }
//  
//    }
//    return 0;
//}
//void rotate(int* nums, int numsSize, int k)
//{
//    int i = 0;
//    for (i = 0; i < k; i++)
//    {
//        int j = 0;
//        for (j = 0; j < numsSize - 1 ; j++)
//        {
//            int tmp = nums[numsSize - j - 2];
//            nums[numsSize - j - 2] = nums[numsSize - j - 1];
//            nums[numsSize - j - 1] = tmp;
//        }
//    }
//}
//int main()
//{
//    int nums[] = { 1,2,3,4,5,6,7 };
//    int k = 3;
//    int sz = sizeof(nums) / sizeof(nums[0]);
//
//    rotate(nums, sz, k);
//
//    return 0;
//}

int main()
{
	int ar[] = {2,3,4,5,6,7,2,3,4,5,6,8 };

	int sz = sizeof(ar) / sizeof(ar[0]);

	int i = 0;
	int j = 0;
	int count = 0;

	for (i = 0; i < sz; i++)
	{
		if (ar[i] % 2 == 1)
		{
			int tmp = ar[j];
			ar[j] = ar[i];
			ar[i] = tmp;
			j++;
			count++;
		}
	}
	int x = 0;
	for (i = 0; i < count; i++)
	{
		x ^= ar[i];
	}
	printf("%d ", x);
	x = 0;
	for (i = sz - 1; i > count - 1 ; i--)
	{
		x ^= ar[i];
	}
	printf("%d ", x);

	return 0;
}