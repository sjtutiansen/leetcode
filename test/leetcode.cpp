#include "leet_code.h"
#include <limits.h>

//No.1 the sum of two int
int comp(const void* a,const void* b)  /*用来做比较的函数。  */
{  
    return *(int*)a-*(int*)b;  
}

int* twoSum(int* nums, int numsSize, int target) {
	int *testtemp = new int[numsSize];
    int *temp = (int*)malloc(sizeof(int)*numsSize);
    for(int k = 0;k < numsSize;++k) temp[k] = nums[k];
    qsort(nums,numsSize,sizeof(int),comp);           /*调用qsort排序*/
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
    free(temp);
    *result = i;
    *(result+1) = j;
    return result;   
}

int test_No1_two_sum() {
	int nums[3] = { 3,2,3 };
	int numsSize = 3, target = 6;
	int* ans;
	ans = twoSum(nums, numsSize, target);
	printf("the answer of No.1 \nfirst:%d second:%d \n", ans[0], ans[1]);
	free(ans);
	return 0;
}

//No.7 Reverse Integer
int reverse(int x) {
	long result = 0;
	long temp = x;
	bool flag = true;
	int a[32] = { 0 };
	int nbits = 0;
	if (temp < 0) {
		temp = -temp;
		flag = false;
	}
	while (temp / 10 > 0) {
		a[nbits] = temp % 10;
		temp = temp / 10;
		++nbits;
	}
	a[nbits] = temp;
	for (int i = 0; i <= nbits; ++i) {
		result = result * 10 + a[i];
	}
	if (flag) {
		if (result > INT_MAX)return 0;
		else return (int)result;
	}
	else {
		result = -result;
		if (result < INT_MIN)return 0;
		else return (int)result;
	}
}

int test_No7_reverse() {
	int a = 1234;
	int ans = reverse(a);
	printf("the answer of No.7 \ninput:%d output:%d \n", a, ans);
	return 0;
}

//N0.9 Palindrome Number
bool isPalindrome(int x) {
	if (x < 0)return false;
	int a[10];
	int nbits = 0;
	while (x / 10 > 0) {
		a[nbits] = x % 10;
		x = x / 10;
		++nbits;
	}
	a[nbits] = x;
	int i = 0, j = nbits;
	while (i <= j) {
		if (a[i] != a[j]) return false;
		++i;
		--j;
	}
	return true;
}

int test_No9_isPalindrome() {
	int a = 1234321;
	if (isPalindrome(a))
		printf("%d is palindrome", a);
	else
		printf("%d isn't palindrome", a);
	return 0;
}

//No.13 Roman to Integer
int romanToInt(char* s) {
	int result = 0;
	while (*s != '\0') {
		if (*s == 'M') {
			result = result + 1000;
			s++;
		}
		else if (*s == 'D') {
			result = result + 500;
			s++;
		}
		else if (*s == 'C') {
			if (*(s + 1) == 'M') {
				result = result + 900;
				s = s + 2;
			}
			else if (*(s + 1) == 'D') {
				result = result + 400;
				s = s + 2;
			}
			else {
				result = result + 100;
				s++;
			}
		}
		else if (*s == 'L') {
			result = result + 50;
			s++;
		}
		else if (*s == 'X') {
			if (*(s + 1) == 'C') {
				result = result + 90;
				s = s + 2;
			}
			else if (*(s + 1) == 'L') {
				result = result + 40;
				s = s + 2;
			}
			else {
				result = result + 10;
				s++;
			}
		}
		else if (*s == 'V') {
			result = result + 5;
			s++;
		}
		else {
			if (*(s + 1) == 'X') {
				result = result + 9;
				s = s + 2;
			}
			else if (*(s + 1) == 'V') {
				result = result + 4;
				s = s + 2;
			}
			else {
				result = result + 1;
				s++;
			}
		}
	}
	return result;
}

int test_No13_romanToInt() {
	char* a = "VIII";
	int b = 0;
	b = romanToInt(a);
	printf("%s is %d", a, b);
	return 0;
}