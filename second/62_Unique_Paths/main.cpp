#include "../include/header.h"

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

/*
 A math solution is: (m + n - 2)! /((m - 1)! * (n - 1)!)
 It’s true that this can be solved with dynamic programming. But you can see that every path has exactly m – 1 horizontal moves and n – 1 vertical moves. So, to get a particular path, you need to choose where to put your m – 1 horizontal moves (or your n – 1 vertical moves) amongst the m + n – 2 total moves. That gives (m+n-2 choose m-1) paths (or (m+n-2 choose n-1), which is the same).
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(0 == m * n)
        {
            return 0;
        }

        vector<vector<int> >dp(m, vector<int> (n, 1));
        for(int row = 1 ; row < m; ++row)
        {
            for(int col = 1; col < n; ++col)
            {
                dp[row][col] = dp[row][col - 1] + dp[row - 1][col];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    int m = 1, n = 2;
    Solution sol;
    int result = sol.uniquePaths(m, n);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}