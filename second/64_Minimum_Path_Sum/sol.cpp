#include "../include/header.h"

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
*/

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int row = grid.size();
        if(0 == row)
        {
            return 0;
        }
        int col = grid[0].size();
        if(0 == col)
        {
            return 0;
        }

        vector<vector<int> > dp(row, vector<int> (col, 0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < row; ++i)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for(int j = 1; j < col; ++j)
        {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for(int i = 1; i < row; ++i)
        {
            for(int j = 1; j < col; ++j)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[row - 1][col - 1];
    }
};

int main()
{
    vector<vector<int> > input = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Solution sol;
    int result = sol.minPathSum(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
