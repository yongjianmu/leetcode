#include "../include/header.h"

class Solution {
public:
    void dfs(int x, int y, pair<int, int> dir, int row, int col, vector<vector<int> > &M, int& cur, int& ret)
    {
        ret = max(ret, cur);
        M[x][y] = 0;
        int nx = x + dir.first, ny = y + dir.second;
        if(nx >= 0 && nx < row && ny >= 0 && ny < col && M[nx][ny] == 1)
        {
            ++cur;
            dfs(nx, ny, dir, row, col, M, cur, ret);
        }
        M[x][y] = 1;
    }

    int longestLine(vector<vector<int> >& M) {
        int ret = 0;
        int row = M.size();
        if(0 == row) return ret;
        int col = M[0].size();
        if(0 == col) return 0;
        
        vector<pair<int, int> > dirs = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1},
            {1, 1},
            {1, -1},
            {-1, 1},
            {-1, -1}
        };
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(1 == M[i][j])
                {
                    for(auto dir : dirs)
                    {
                        int cur = 1;
                        dfs(i, j, dir, row, col, M, cur, ret);
                    }
                }
            }
        }
        
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<vector<int> > input = {
        {0,1,1,0},
        {0,1,1,0},
        {0,0,0,1}
    };
    int result = sol.longestLine(input);
    printResult();
    cout << result << endl;
}
