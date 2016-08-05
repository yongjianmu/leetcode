#include "../include/header.h"

/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
*/

class Solution {
public:
    vector<string> mRet;

    void solve(int x, int y, int dx[], int dy[], int row, int col, string& cur, string des, bool& flag,\
                vector<vector<char> > board, vector<vector<bool> >& vis, unordered_map<string, bool>& dict)
    {
        if(cur == des)
        {
            if(dict.find(cur) != dict.end())
            {
                flag = true;
                return;
            }
            mRet.push_back(cur);
            dict[cur] = true;
            flag = true;
            return;
        }

        if(flag || cur.size() >= des.size())
        {
            return;
        }

        for(int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && row > nx && 0 <= ny && col > ny && board[nx][ny] == des[cur.size()] && !vis[nx][ny])
            {
                cur.push_back(board[nx][ny]);
                vis[nx][ny] = true;
                solve(nx, ny, dx, dy, row, col, cur, des, flag, board, vis, dict);
                vis[nx][ny] = false;
                cur.pop_back();
            }
        }
    }

    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        int row = board.size();
        if(0 == row)
        {
            return mRet;
        }
        int col = board[0].size();
        if(0 == col)
        {
            return mRet;
        }
        int size = words.size();
        if(0 == size)
        {
            return mRet;
        }

        unordered_map<char, vector<string> > ump;
        unordered_map<string, bool> dict;
        for(int i = 0; i < size; ++i)
        {
            ump[words[i][0]].push_back(words[i]);
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(ump.find(board[i][j]) != ump.end())
                {
                    vector<string> des = ump[board[i][j]];
                    for(int k = 0; k < des.size(); ++k)
                    {
                        if(dict.find(des[k]) != dict.end())
                        {
                            continue;
                        }
                        vector<vector<bool> > vis(row, vector<bool>(col, 0));
                        vis[i][j] = true;
                        string cur = "";
                        cur.push_back(des[k][0]);
                        bool flag = false;
                        solve(i, j, dx, dy, row, col, cur, des[k], flag, board, vis, dict);
                        if(flag)
                        {
                            auto iter = find(ump[board[i][j]].begin(), ump[board[i][j]].end(), des[k]);
                            ump[board[i][j]].erase(iter);
                            if(0 == ump[board[i][j]].size())
                            {
                                auto it = ump.find(board[i][j]);
                                ump.erase(it);
                            }
                        }
                    }
                }
            }
        }

        return mRet;
    }
};

int main()
{
    vector<string> words ={"oath","pea","eat","rain"};
    vector<vector<char> > board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    Solution sol;
    vector<string> result = sol.findWords(board, words);
    printResult();
    printVector1D(result, true);

    return 0;
}
