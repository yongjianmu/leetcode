// 7_Reverse_Integer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../include/header.h"

/*Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321 
*/

class Solution {
public:
    int reverse(int x) {
        if (0 == x)
        {
            return x;
        }

        bool flag = false;
        if (0 > x)
        {
            x = -x;
            flag = true;
        }

        long long ret = 0;
        while (0 != x)
        {
            ret = (ret * 10) + (x % 10);
            x /= 10;
        }

        if (flag)
        {
            ret = -ret;
        }

        if (ret > INT_MAX || ret < INT_MIN)
        {
            return 0;
        }

        return static_cast<int> (ret);
    }
};

int main()
{
    int input = 1534236469;
    Solution sol;
    int result = sol.reverse(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}

