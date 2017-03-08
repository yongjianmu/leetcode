#include "../../second/include/header.h"


bool canErase(vector<vector<int> >& matrix, int row, int col)
{
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0 ; j < col; ++j)
        {
            if(i != row - 1 && matrix[i][j] >= 0 && matrix[i][j] == matrix[i + 1][j]) return true;
            if(j != col - 1 && matrix[i][j] >= 0 && matrix[i][j] == matrix[i][j + 1]) return true;
        }
    }
    return false;
}

void dfs(int x, int y, vector<vector<int> >& matrix, int row, int col, vector<vector<bool> >& vis, unordered_map<int, vector<int> >& ump, int dx[], int dy[])
{
    ump[y].push_back(x);
    vis[x][y] = true;
    for(int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= row || ny < 0 || ny >= col || vis[nx][ny] || matrix[nx][ny] != matrix[x][y]) continue;
        dfs(nx, ny, matrix, row, col, vis, ump, dx, dy);
    }
}

int erase(int x, int y, vector<vector<int> >& matrix, int row, int col, bool& end_game)
{
    vector<vector<bool> > vis(row, vector<bool>(col, false)); 
    unordered_map<int, vector<int> > ump;
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    dfs(x, y, matrix, row, col, vis, ump, dx, dy);

    int sum = 0;
    for(auto iter = ump.begin(); iter != ump.end(); ++iter)
    {
        // update by col
        int cnt = iter->second.size();
        if(0 == cnt) continue;
        sum += cnt;

        int x_max = 0, x_min = row;
        for(auto it = iter->second.begin(); it != iter->second.end(); ++it)
        {
            matrix[*it][iter->first] = -1;
            x_max = max(x_max, *it);
            x_min = min(x_min, *it);
        }

        // fall down
        int x_start = x_min - 1;
        while(x_start >= 0)
        {
            swap(matrix[x_max--][iter->first], matrix[x_start--][iter->first]);
        }
    }

    // check end
    if(!canErase(matrix, row, col)) end_game = true;
    return (1 + sum) * sum / 2;
}


int main()
{
    vector<vector<int> > input = {
        {1,0,2,3,1,4,5,6},
        {1,0,2,3,1,4,5,6},
        {1,0,2,3,1,1,5,7},
        {4,0,2,3,2,4,3,6},
        {1,5,2,4,1,2,5,6},
        {2,0,2,3,3,4,6,6},
        {1,6,3,3,1,5,5,6},
        {1,0,2,3,1,4,5,6}
    };

    bool flag = true;
    int score = erase(7, 3, input, 8, 8, flag);
    printVector2D(input);
    printResult();
    cout << score << ",  can still play? " << flag << endl;
    return 0;
}
