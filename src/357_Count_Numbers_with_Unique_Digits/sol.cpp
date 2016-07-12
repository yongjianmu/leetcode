#include "../include/header.h"

/*
Given a non-negative integer n, count all numbers with unique digits, x, where 0 = x < 10n.

Example:
 Given n = 2, return 91. (The answer should be the total numbers in the range of 0 = x < 100, excluding [11,22,33,44,55,66,77,88,99]) 
 */
 
 class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        n = min(n, 10);
		vector<int> dp(n + 1, 9);
		dp[0] = 1;
		for(int i = 2; i <= n; ++i)
		{
			for(int j = 9; j >= 9 - i + 2; --j)
			{
				dp[i] *= j;
			}
		}
		
		int ret = 0;
		for(int i = 0; i < dp.size(); ++i)
		{
			ret += dp[i];
		}
		
		return ret;
    }
};
