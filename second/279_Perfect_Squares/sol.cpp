#include "../include/header.h"

/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

class Solution {
public:

    int numSquares(int n) {
        vector<int> dp(n + 1, 0);

        for(int i = 0; i <= n; ++i)
        {
            dp[i] = i;
            for(int j = 1; j * j <= i; ++j)
            {
                int j2 = i - j * j;
                if(dp[j2] + 1 < dp[i])
                {
                    dp[i] = dp[j2] + 1;
                }
            }
        }
        return dp[n];
    }
};

int main()
{
    int n = 12;
    Solution sol;
    int result = sol.numSquares(n);
    printResult();
    cout << result << endl;

    return 0;
}
