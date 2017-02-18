#include "../../second/include/header.h"

struct node
{
    int val;
    vector<int> path;
    node() : val(-1) {}
};

class Solution
{
public:
    node dfs(vector<vector<int> >& matrix, int row, int col, int x, int y, vector<vector<node> >& dp, vector<vector<bool> >& vis, vector<pair<int, int> >& dir)
    {
        int cur_len = 1;
        vector<int> path = {matrix[x][y]};
        for(auto d : dir)
        {
            int nx = x + d.first, ny = y + d.second;
            if(nx < 0 || nx >= row || ny < 0 || ny >= col || abs(matrix[nx][ny] - matrix[x][y]) <= 3 || vis[nx][ny]) continue;
            if(matrix[nx][ny] > matrix[x][y] && dp[nx][ny].val > 0)
            {
                if(cur_len < dp[nx][ny].val + 1)
                {
                    cur_len = dp[nx][ny].val + 1;
                    path = dp[nx][ny].path;
                    path.insert(path.begin(), matrix[x][y]);
                }
                continue;
            }

            vis[x][y] = true;
            node cur = dfs(matrix, row, col, nx, ny, dp, vis, dir);
            vis[x][y] = false;
            if(cur_len < cur.val + 1)
            {
                cur_len = cur.val + 1;
                path = cur.path;
                path.insert(path.begin(), matrix[x][y]);
            }
        }
        
        node ret;
        ret.val = cur_len;
        ret.path = path;
        return ret;
    }

    vector<int> longestPath(vector<vector<int> >& matrix)
    {
        int row = matrix.size();
        if(0 == row) return vector<int>(0);
        int col = matrix[0].size();
        if(0 == col) return vector<int>(0);

        vector<vector<node> > dp(row, vector<node>(col, node()));
        vector<vector<bool> > vis(row, vector<bool>(col, false));
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

        int maxV = 1;
        pair<int, int> maxNode;
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                node cur = dfs(matrix, row, col, i, j, dp, vis, dir);
                dp[i][j] = cur;
                if(cur.val > maxV)
                {
                    maxV = cur.val;
                    maxNode = {i, j};
                }
            }
        }
        return dp[maxNode.first][maxNode.second].path;
    }
};

int main()
{
    vector<vector<int> > input = {
        {8,2,4},
        {0,6,1},
        {3,7,9}
    };
    Solution sol;
    vector<int> result = sol.longestPath(input);
    printResult();
    printVector1D(result);
    return 0;
}