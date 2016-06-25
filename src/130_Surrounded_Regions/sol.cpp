#include <vector>
#include <queue>
#include <iostream>

using namespace std;


/*
For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

class Solution {
public:
    typedef struct 
    {
        int x;
        int y;
    } tNode;

    void solve(vector<vector<char> >& board) {
        int row = board.size();
        if(0 == row)
        {
            return;
        }

        int col = board.size();
        if(0 == col)
        {
            return;
        }

        vector<vector<bool> > vis(row, vector<bool>(col, false));
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if('X' == board[i][j] || vis[i][j])
                {
                    continue;
                }

                // find 'O'
                bool flag = true; // Change flag;
                queue<tNode> q;
                queue<tNode> q2;

                tNode node;
                node.x = i;
                node.y = j;

                q.push(node);
                q2.push(node);

                while(!q.empty())
                {
                    int curx = q.front().x;
                    int cury = q.front().y;
                    q.pop();

                    for(int k = 0; k < 4; ++k)
                    {
                        int nx = dx[k] + curx;
                        int ny = dy[k] + cury;

                        if((0 > nx || col <= nx) || (0 > ny || row <= ny)) // touch border
                        {
                            flag = false;
                            continue;
                        }

                        if('X' == board[nx][ny] || vis[nx][ny])
                        {
                            continue;
                        }

                        vis[nx][ny] = true;
                        tNode tmp;
                        tmp.x = nx;
                        tmp.y = ny;
                        q.push(tmp);
                        q2.push(tmp);
                    }

                }

                if(flag)
                {
                    while(!q2.empty())
                    {
                        int x = q2.front().x;
                        int y = q2.front().y;
                        board[x][y] = 'X';
                        q2.pop();
                    }
                }
            }
        }
    }
};

int main()
{
    return 0;
}
