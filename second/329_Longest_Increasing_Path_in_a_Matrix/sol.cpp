#include "../include/header.h"

/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

class Solution {
public:

    int solve(int x, int y, int dx[], int dy[], int row, int col, vector<vector<int> >& dp, vector<vector<int> >&matrix)
    {
        if(0 != dp[x][y])
        {
            return dp[x][y];
        }

        for(int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && row > nx && 0 <= ny && col > ny && matrix[nx][ny] > matrix[x][y])
            {
                dp[x][y] = max(dp[x][y], solve(nx, ny, dx, dy, row, col, dp, matrix));
            }
        }
        return ++dp[x][y];
    }

    int longestIncreasingPath(vector<vector<int> >& matrix) {
        int ret = 0;
        int row = matrix.size();
        if(0 == row)
        {
            return ret;
        }
        int col = matrix[0].size();
        if(0 == col)
        {
            return ret;
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        vector<vector<int> > dp(row, vector<int>(col, 0));
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                ret = max(ret, solve(i, j, dx, dy, row, col, dp, matrix));
            }
        }

        return ret;
    }
};

int main()
{
    vector<vector<int> >input = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    Solution sol;
    int result = sol.longestIncreasingPath(input);
    printResult();
    cout << result << endl;

    return 0;
}
