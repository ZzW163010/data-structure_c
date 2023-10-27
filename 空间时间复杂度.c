#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

//找出一个已有数列中的缺失值

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

//找出一个数列中两个不重复值

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

//轮转数组

void reserve(int * nums,int left, int right)
{
   while(left <right)
   {
      int tmp = nums[left];
      nums[left] = nums[right];
      nums[right] = tmp;
      left++;
      right--;
    }
}
void rotate(int* nums, int numsSize, int k)
{
    if(k>numsSize)
    {
        k %= numsSize;
    }
    reserve(nums,0, numsSize - k - 1);
    reserve(nums,numsSize - k, numsSize - 1);
    reserve(nums,0, numsSize - 1);

//k>numsSize的处理方式
//第一种
//    if(numsSize >= k)
//     {
//        reserve(nums,0, numsSize - k - 1);
//        reserve(nums,numsSize - k, numsSize - 1);
//        reserve(nums,0, numsSize - 1);
//     }
//    else
//     {
//        while(k--)
//         {
//           int tmp = nums[numsSize - 1];
//           int i = 0;
//           for(i = 0;i < numsSize - 1; i++)
//           {
//              nums[numsSize - 1 - i] = nums[numsSize - 2 - i];
//           }  
//           nums[0] = tmp;
//         }
//     }

}
