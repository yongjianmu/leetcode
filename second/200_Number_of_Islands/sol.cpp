#include "../include/header.h"

/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/

class Solution {
public:

    void check(int x, int y, int dx[], int dy[], int row, int col, vector<vector<bool> >& vis, vector<vector<char> > grid)
    {
        if(vis[x][y])
        {
            return;
        }

        vis[x][y] = true;
        for(int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && row > nx && 0 <= ny && col > ny && '1' == grid[nx][ny])
            {
                check(nx, ny, dx, dy, row, col, vis, grid);
            }
        }
    }

    int numIslands(vector<vector<char> >& grid) {
        int ret = 0;
        int row = grid.size();
        if(0 == row)
        {
            return ret;
        }
        int col = grid[0].size();
        if(0 == col)
        {
            return ret;
        }

        vector<vector<bool> > vis(row, vector<bool>(col, false));
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if('1' == grid[i][j] && !vis[i][j])
                {
                    ++ret;
                    check(i, j, dx, dy, row, col, vis, grid);
                }
            }
        }

        return ret;
    }
};

int main()
{
    vector<vector<char> > input = {
        {'1', '1', '1', '0', '0'},
        {'0', '1', '0', '0', '0'},
        {'1', '1', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
    };
    Solution sol;
    int result = sol.numIslands(input);
    printResult();
    cout << result << endl;

    return 0;
}
