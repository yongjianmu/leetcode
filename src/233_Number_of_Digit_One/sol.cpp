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
        if(0 >= n)
        {
            return 0;
        }

        int ret = 0;
        int digit = 1;
        int num = n;
        while(0 != num)
        {
            int x = num % 10;
            int sign = x > 0 ? 1 : 0;
            num /= 10;
            int a = num * digit;
            int b = sign * (x == 1 ? n % digit + 1 : digit);
            ret += a + b;
            digit *= 10;
        }
        return ret;
    }
};

int main()
{
    int n = 15;
    Solution sol;
    int result = sol.countDigitOne(n);
    cout << result << endl;

    return 0;
}
