#include "../../second/include/header.h"

class Solution
{
public:
    int dfs(vector<vector<int> >& matrix, int row, int col, int x, int y, vector<vector<int> >& dp, vector<pair<int, int> >& dir)
    {
        if(0 < dp[x][y]) return dp[x][y];
        int ret = 1;
        for(auto d : dir)
        {
            int nx = x + d.first, ny = y + d.second;
            if(nx < 0 || nx >= row || ny < 0 || ny >= col || matrix[nx][ny] < matrix[x][y] || 0 == dp[nx][ny]) continue;
            dp[x][y] = 0;
            ret = max(ret, 1 + dfs(matrix, row, col, nx, ny, dp, dir));
            dp[x][y] = -1;
        }
        dp[x][y] = ret;
        return ret;
    }

    int longestPath(vector<vector<int> >& matrix)
    {
        int row = matrix.size();
        if(0 == row) return 0;
        int col = matrix[0].size();
        if(0 == col) return 0;

        vector<vector<int> > dp(row, vector<int>(col, -1));
        //vector<vector<bool> > vis(row, vector<int>(col, false));
        vector<pair<int, int> > dir = {
            {0, -1},
            {0, 1},
            {-1, 0},
            {1, 0},
            {-1, -1},
            {-1, 1},
            {1, -1},
            {1, 1}
        };

        int ret = 1;
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                ret = max(ret, dfs(matrix, row, col, i, j, dp, dir));
            }
        }
        return ret;
    }
};

int main()
{
    vector<vector<int> > input = {
        {8,2,4},
        {0,7,1},
        {3,7,9}
    };
    Solution sol;
    int result = sol.longestPath(input);
    printResult();
    cout << result << endl;
    return 0;
}
