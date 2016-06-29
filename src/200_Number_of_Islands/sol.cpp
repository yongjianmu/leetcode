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
    int mRow;
    int mCol;
    void dfs(int row, int col, vector<vector<char> >&grid, vector<vector<bool> >&vis)
    {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for(int i = 0; i < 4; ++i)
        {
            int nx = row + dx[i];
            int ny = col + dy[i];

            if(nx < 0 || nx >= mRow || ny < 0 || ny >= mCol || vis[nx][ny] || '0' == grid[nx][ny])
            {
                continue;
            }
            vis[nx][ny] = true;
            dfs(nx, ny, grid, vis);
        }
    }

    int numIslands(vector<vector<char> >& grid) {
        mRow = grid.size();
        if(0 == mRow)
        {
            return 0;
        }
        mCol = grid[0].size();
        if(0 == mCol)
        {
            return 0;
        }

        vector<vector<bool> > vis(mRow, vector<bool>(mCol, false));
        int ret = 0;

        for(int i = 0; i < mRow; ++i)
        {
            for(int j = 0; j < mCol; ++j)
            {
                if(!vis[i][j] && '1' == grid[i][j])
                {
                    vis[i][j] = true;
                    dfs(i, j, grid, vis);
                    ++ret;
                }
            }
        }
        return ret;
    }
};

int main()
{
    return 0;
}
