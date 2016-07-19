#include "../include/header.h"

/*
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
        There exist two distinct solutions to the 4-queens puzzle:

[
[".Q..",  // Solution 1
"...Q",
"Q...",
"..Q."],

["..Q.",  // Solution 2
"Q...",
"...Q",
".Q.."]
]
*/

class Solution {
public:
    //vector<vector<int> > mPos;
    vector<vector<string> > mRet;

    bool check(int cur, vector<int> row)
    {
        for(int i = 0; i < cur; ++i)
        {
            if(row[cur] == row[i] || abs(row[cur] - row[i]) == cur - i)
            {
                return false;
            }
        }
        return true;
    }

    void solve(int cur, int n, vector<int>& row, vector<string>& q_row)
    {
        if(cur == n)
        {
            //mPos.push_back(row);
            mRet.push_back(q_row);
            return;
        }

        for(int i = 0; i < n; ++i)
        {
            row[cur] = i;
            q_row[cur][i] = 'Q';
            if(check(cur, row))
            {
                solve(cur + 1, n, row, q_row);
            }
            q_row[cur][i] = '.';
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<int> row(n , -1); /* row[0]: the col number of the 0th row */
        vector<string> q_row(n, string(n, '.'));
        solve(0, n, row, q_row);
        return mRet;
    }
};

int main() {
    int n = 8;
    Solution sol;
    vector<vector<string> > result = sol.solveNQueens(n);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        for(int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << endl;
        }
        cout << "*********************" << endl;
    }

    return 0;
}