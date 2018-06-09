#include "leet_code.h"
#include <limits.h>

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

int test_reverse() {
	int a = 1234;
	int ans = reverse(a);
	printf("input:%d output:%d", a, ans);
	return 0;
}