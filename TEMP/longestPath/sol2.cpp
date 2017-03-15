#include <vector>
#include <iostream>
using namespace std;

struct node
{
    int val;
    vector<int> path;
    node() : val(-1) {}
};

class Solution
{
public:
    node dfs(vector<vector<int> >& matrix, int row, int col, int x, int y, vector<vector<node> >& dp, vector<pair<int, int> >& dir)
    {
        if(0 < dp[x][y].val) return dp[x][y];
        int ret = 1;
        vector<int> path = {matrix[x][y]};
        for(auto d : dir)
        {
            int nx = x + d.first, ny = y + d.second;
            if(nx < 0 || nx >= row || ny < 0 || ny >= col || matrix[nx][ny] < matrix[x][y] || 0 == dp[nx][ny].val) continue;
            dp[x][y].val = 0;
            node cur = dfs(matrix, row, col, nx, ny, dp, dir);
            if(ret < cur.val + 1)
            {
                ret = cur.val + 1;
                path = cur.path;
                path.insert(path.begin(), matrix[x][y]);
            }
            dp[x][y].val = -1;
        }
        dp[x][y].val = ret;
        dp[x][y].path = path;
        return dp[x][y];
    }

    vector<int> longestPath(vector<vector<int> >& matrix)
    {
        int row = matrix.size();
        if(0 == row) return vector<int>(0);
        int col = matrix[0].size();
        if(0 == col) return vector<int>(0);

        vector<vector<node> > dp(row, vector<node>(col, node()));
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
                node cur = dfs(matrix, row, col, i, j, dp, dir);
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
        {6,4,4},
        {4,4,7},
        {3,7,9}
    };
    Solution sol;
    vector<int> result = sol.longestPath(input);
    for(auto& r : result)
    {
        cout << r << "=>";
    }
    cout << endl;
    return 0;
}
