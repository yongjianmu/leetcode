#include "../include/header.h"

/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:

    bool solve(int x, int y, int pos, int dx[], int dy[], \
                vector<vector<bool> >& vis, int row, int col, int len, \
                vector<vector<char> >& board, string word)
    {
        if(pos > len - 1)
        {
            return true;
        }

        for(int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && row > nx && 0 <= ny && col > ny && board[nx][ny] == word[pos] && !vis[nx][ny])
            {
                vis[nx][ny] = true;
                if(solve(nx, ny, pos + 1, dx, dy, vis, row, col, len, board, word))
                {
                    return true;
                }
                vis[nx][ny] = false;
            }
        }
        return false;
    }

    bool exist(vector<vector<char> >& board, string word) {
        int row = board.size();
        if(0 == row)
        {
            return false;
        }
        int col = board[0].size();
        if(0 == col)
        {
            return false;
        }
        int len = word.length();
        if(0 == len)
        {
            return false;
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        vector<vector<bool> > vis(row, vector<bool>(col, false));
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(board[i][j] == word[0])
                {
                    vis[i][j] = true;
                    if(solve(i, j, 1, dx, dy, vis, row, col, len, board, word))
                    {
                        return true;
                    }
                    vis[i][j] = false;
                }
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<char> > input = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    Solution sol;
    bool result = sol.exist(input, word);
    cout << "##### Result ####" << endl;
    cout << result << endl;

    return 0;
}
