#ifndef LEET_CODE_H
#define LEET_CODE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//No.1 the sum of two int
int test_No1_two_sum();

//No.7 Reverse Integer
int test_No7_reverse();

//No.9 Palindrome Number
int test_No9_isPalindrome();

//No.13 Roman to Integer
int test_No13_romanToInt();

//No.14 Longest Common Prefix
int test_No14_longestCommonPrefix();

//No.20 Valid Parentheses
int test_No20_Valid_Parentheses();

//No.21 Merge Two Sorted Lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

//No.26 Remove Duplicates from Sorted Array
int test_No26_removeDuplicates();

//No.27 Remove Element
int test_No27_removeElement();

//No.28 Implement strStr()
int strStr(string haystack, string needle);

#endif