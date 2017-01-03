#include <iostream>
#include <vector>
#include <random>
#include <time.h>
using namespace std;

class Solution
{
private:
    int mRow;
    int mCol;
    int mTotal;
    int mHit;
    int mLeft;
    int mCheckCnt;

public:
    void initBoard(vector<vector<int> >& board, int total)
    {
        mRow = board.size();
        mCol = board[0].size();
        mTotal = total;
        mHit = 0;
        mCheckCnt = 0;
        srand(time(NULL));
    }

    bool check(vector<vector<int> >& board, pair<int, int> coordinate)
    {
        if(board[coordinate.first][coordinate.second]) return true;
        return false;
    }

    pair<int, int> randomSampling(vector<vector<int> >& board, vector<vector<bool> >& vis)
    {
        pair<int, int> ret;
        int cnt = 0;
        for(int i = 0; i < mRow; ++i)
        {
            for(int j = 0; j < mCol; ++j)
            {
                if(vis[i][j]) continue;
                ++cnt;
                if(rand() % cnt == 0) ret = {i, j};
            }
        }
        return ret;
    }

    void dfs(int x, int y, int dx[], int dy[], vector<vector<int> >& board, vector<vector<bool> >& vis)
    {
        if(++mHit == mTotal) return;

        for(int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= mRow || ny < 0 || ny >= mCol || vis[nx][ny]) continue;
            
            vis[nx][ny] = true;
            ++mCheckCnt;
            if(!check(board, {nx, ny}))
            {
                continue;
            }
            
            dfs(nx, ny, dx, dy, board, vis);
        }
    }

    int getCheckCounts()
    {
        return mCheckCnt;
    }

    void mainLoop(vector<vector<int> >& board)
    {
        vector<vector<bool> > vis(mRow, vector<bool>(mCol, false));
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        while(mHit < mTotal)
        {
            pair<int, int> curNode = randomSampling(board, vis);
            vis[curNode.first][curNode.second] = true;
            ++mCheckCnt;
            if(!check(board, curNode))
            {
                continue;
            }

            dfs(curNode.first, curNode.second, dx, dy, board, vis);
        }
    }
};

int main()
{
    vector<vector<int> > board = 
    {
        {0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,1,0,1,0},
        {0,0,0,0,0,0,1,0,1,0},
        {0,0,0,0,1,1,1,0,1,0},
        {0,0,0,0,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    
    Solution sol;
    sol.initBoard(board, 15);
    sol.mainLoop(board);
    cout << sol.getCheckCounts() << endl;
    return 0;
}
