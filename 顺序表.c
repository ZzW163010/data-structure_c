//合并两个有序数组（合并结果也保证有序）

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
   int p1 = m - 1;
   int p2 = n - 1;
   int end = m + n - 1;

   if(n == 0){
       return;
   }
   else{
       while(p1 >= 0 && p2 >= 0){
           if(nums1[p1] > nums2[p2]){
               nums1[end] = nums1[p1];
               p1--;
               end--;
           }
           else{
               nums1[end] = nums2[p2];
               p2--;
               end--;
           }
       } 
       if(p1 < 0){
           while(p2 >= 0){
               nums1[p2] = nums2[p2];
               p2--;
           }
       } 
   } 
}



// void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
//     if(n == 0){
//         return;
//     }
//     else{
//         while(n){
//         nums1[m] = nums2[n - 1];
//         n--;
//         m++;
//     }
//         }
    
//     for(int i = 0; i < nums1Size - 1; i++){
//         int flag = 0;
//         for(int j = 0; j < nums1Size - 1- i; j++){
//             if(nums1[j] > nums1[j + 1]){
//                 int tmp = nums1[j];
//                 nums1[j] = nums1[j + 1];
//                 nums1[j + 1] = tmp;
//                 flag = 1;
//             }
//         }
//         if(!flag){
//             break;
//         }
//     }
// }


//从顺序表中删除指定元素（不止一个）

// int removeElement(int* nums, int numsSize, int val) {
   
//    int *src = nums;
//    int *dst = nums;

//    for(int i = 0; i < numsSize; i++){
//        if(nums[i] == val){
//            src++;
//        }
//        else{
//            *dst++ = *src;
//        }
//    }
//    return numsSize -= (src-dst);
// }


int removeElement(int* nums, int numsSize, int val) {
   
   int src = 0;
   int dst = 0;

   while(src < numsSize){
       if(nums[src] == val){
           src++;
       }
       else{
           nums[dst++] = nums[src++];
       }
   }
   return dst;
}

// int removeElement(int* nums, int numsSize, int val) {
   
//     int len = numsSize;
//     for (int j = 0; j < len; j++){
//         int flag = 0;
//         for (int i = 0; i < numsSize; i++) {
//             if (nums[i] == val) {
//                 int tmp = nums[numsSize - 1];
//                 nums[numsSize - 1] = nums[i];
//                 nums[i] = tmp;
//                 flag = 1;
//                 numsSize--;
//             }
//         }
//         if (!flag)
//         {
//             break;
//         }
//     }
//     return numsSize;
// }
