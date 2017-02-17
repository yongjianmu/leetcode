#include "../../second/include/header.h"

int dfs(vector<vector<int> >& grid, int row, int col, int x, int y, vector<vector<int> >& dp, vector<vector<bool> >& vis, vector<pair<int, int> >& dir){
    int cur_len = 1;
    vis[x][y] = true;
    for(auto d: dir){
        int nx = x + d.first, ny = y + d.second;
        if(nx < 0 || nx >= row || ny < 0 || ny >= col || abs(grid[nx][ny] - grid[x][y]) <= 3 || vis[nx][ny]){
            continue;
        }
        
        // cut off, if the value already exists, just update it.
        if(grid[nx][ny] > grid[x][y] && dp[nx][ny] > 0){
            cur_len = max(cur_len, dp[nx][ny] + 1);
            continue;
        }
        
        int tmp = dfs(grid, row, col, nx, ny, dp, vis, dir);
        cur_len = max(cur_len, tmp + 1);
    }
    return cur_len;
}

/**
 * Take a rectangular grid of numbers and find the length
 * of the longest sub-sequence.
 * Return the length as an integer.
 */
int longest_subsequence(vector< vector<int> > grid) {
    // TODO: Complete this function
    int row = grid.size();
    if(0 == row) return 0;
    int col = grid[0].size();
    if(0 == col) return 0;
    
    vector<vector<int> > dp(row, vector<int>(col, -1));
    vector<vector<bool> > vis(row, vector<bool> (col, false));
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
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            int cur = dfs(grid, row, col, i, j, dp, vis, dir);
            dp[i][j] = cur;
            ret = max(cur, ret);
        }
    }
    return ret;
}

int main()
{
    vector<vector<int> > input = {
        {8,2,4},
        {0,6,1},
        {3,7,9}
    };
    int result = longest_subsequence(input);
    printResult();
    cout << result << endl;
    return 0;
}
