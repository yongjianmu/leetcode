#include "../include/header.h"

/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
*/

class Solution {
public:
    int countDigitOne(int n) {
        int ret = 0;
        int cnt = 1, num = n;

        while(0 != num)
        {
            int value = num % 10;
            int sign = value > 0 ? 1 : 0;
            num /= 10;
            int a = num * cnt;
            int b = sign * (1 == value ? n % cnt + 1 : cnt);
            ret += a + b;
            cnt *= 10;
        }
        return ret;
    }
};
