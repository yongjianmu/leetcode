#include "../../second/include/header.h"

class Solution
{
public:
    void dfs(vector<vector<int> >& matrix, int row, int col, int x, int y, vector<vector<bool> >& dp, vector<pair<int, int> >& dir, vector<int>& cur_path, vector<int>& ret)
    {
        cur_path.push_back(matrix[x][y]);
        if(ret.size() < cur_path.size()) ret = cur_path;

        for(auto d : dir)
        {
            int nx = x + d.first, ny = y + d.second;
            if(nx < 0 || nx >= row || ny < 0 || ny >= col || matrix[nx][ny] < matrix[x][y] || true == dp[nx][ny]) continue;
            dp[x][y] = true;
            dfs(matrix, row, col, nx, ny, dp, dir, cur_path, ret);
            dp[x][y] = false;
        }
        cur_path.pop_back();
    }

    vector<int> longestPath(vector<vector<int> >& matrix)
    {
        vector<int> ret;
        int row = matrix.size();
        if(0 == row) return ret;
        int col = matrix[0].size();
        if(0 == col) return ret;

        vector<vector<bool> > dp(row, vector<bool>(col, false));
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

        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                vector<int> cur_path;
                dfs(matrix, row, col, i, j, dp, dir, cur_path, ret);
            }
        }
        return ret;
    }
};

int main()
{
    vector<vector<int> > input = {
        {1,4,4},
        {4,7,4},
        {3,4,9}
    };
    Solution sol;
    vector<int> result = sol.longestPath(input);
    printResult();
    printVector1D(result);
    return 0;
}
