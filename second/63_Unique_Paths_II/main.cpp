#include "../include/header.h"

/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int row = obstacleGrid.size();
        if(0 == row)
        {
            return 0;
        }
        int col = obstacleGrid[0].size();
        if(0 == col)
        {
            return 0;
        }
        if(1 == obstacleGrid[0][0] || 1 == obstacleGrid[row - 1][col - 1])
        {
            return 0;
        }

        vector<vector<int> > dp(row + 1, vector<int> (col + 1, 0));
        dp[1][1] = 1; /* Start point */
        for(int i = 1; i <= row; ++i)
        {
            for(int j = 1; j <= col; ++j)
            {
                if(1 == i && 1 == j)
                {
                    continue;
                }

                if(1 == obstacleGrid[i - 1][j - 1])
                {
                    dp[i][j] = -1;
                    continue;
                }

                if(-1 == dp[i - 1][j] && -1 == dp[i][j - 1])
                {

                }
                else if(-1 == dp[i - 1][j])
                {
                    dp[i][j] = dp[i][j - 1];
                }
                else if(-1 == dp[i][j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[row][col];
    }
};

int main() {
    vector<vector<int> > input = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };
    Solution sol;
    int result = sol.uniquePathsWithObstacles(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}