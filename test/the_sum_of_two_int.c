/*
Given an array of integers, return indices of the two numbers 
such that they add up to a specific target.
You may assume that each input would have exactly one solution, 
and you may not use the same element twice.
*/

#include "leet_code.h"

int comp(const void*a,const void*b)//用来做比较的函数。  
{  
    return *(int*)a-*(int*)b;  
}

int* twoSum(int* nums, int numsSize, int target) {
    int temp[numsSize];
    for(int k = 0;k < numsSize;++k) temp[k] = nums[k];
    qsort(nums,numsSize,sizeof(int),comp);//调用qsort排序
    int* result = (int*)malloc(sizeof(int)*2);
    int i = 0, j = numsSize-1;
    while(i < j){
        if((nums[i] + nums[j]) > target) --j;
        else if((nums[i] + nums[j]) > target) ++i;
        else break;
    }
    for(int I = 0;I < numsSize;++I){
        if(temp[I] == nums[i]) {
            *result = I;
            break;
        }
    }
    for(int J = 0;J < numsSize;++J){
        if(temp[J] == nums[j]) {
            *(result+1) = J;
            break;
        }
    }
    *result = i;
    *(result+1) = j;
    return result;   
}