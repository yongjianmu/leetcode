#include "../include/header.h"

/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ret(n, vector<int> (n, 0));
        if(0 == n)
        {
            return ret;
        }
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        int cnt = 0, x = 0, y = 0, num = 2;
        bool quit_flag = false;
        ret[0][0] = 1;
        while(true)
        {
            int index = cnt % 4;
            int nx = x + dx[index];
            int ny = y + dy[index];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && 0 == ret[nx][ny])
            {
                quit_flag = false;
                ret[nx][ny] = num++;
                x = nx;
                y = ny;
            }
            else
            {
                if(quit_flag)
                {
                    break;
                }
                quit_flag = true;
                ++cnt;
            }
        }
        return ret;
    }
};

int main() {
    int n = 4;
    Solution sol;
    vector<vector<int> > result = sol.generateMatrix(n);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        for(int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}