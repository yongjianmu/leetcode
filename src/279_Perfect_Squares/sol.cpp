#include "../include/header.h"


/*
   Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

   For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
   */


class Solution {
public:
    int numSquares(int n) {
        int *dp = new int[n + 1];
        for (int i = 0; i <= n; i++) 
        {
            dp[i] = i;
            for (int j = 1; j * j <= i; j++) 
            {
                if (dp[i - j*j] + 1 < dp[i])
                {
                    dp[i] = dp[i - j*j] + 1;
                }
            }
        }
        int ret = dp[n];
        delete [] dp;
        return ret;
    }
};

int main()
{
    int n = 1;
    Solution sol;
    int result = sol.numSquares(n);
    cout << "#### Result ####" << endl;
    cout << result <<endl;

    return 0;
}
