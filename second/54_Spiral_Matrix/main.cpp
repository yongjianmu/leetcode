#include "../include/header.h"

/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ret;
        int row = matrix.size();
        if(0 == row)
        {
            return ret;
        }
        int col = matrix[0].size();
        if(0 == col)
        {
            return ret;
        }

        vector<vector<bool> > vis(row, vector<bool>(col, false));
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        int cnt = 0;
        int x = 0, y = 0;
        bool quit_flag = false;
        ret.push_back(matrix[0][0]);
        vis[0][0] = true;
        while(true)
        {
            int dir = cnt % 4;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(0 <= nx && row > nx && 0 <= ny && col > ny && !vis[nx][ny])
            {
                quit_flag = false;
                ret.push_back(matrix[nx][ny]);
                vis[nx][ny] = true;
                x = nx, y = ny;
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
    vector<vector<int> > matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    Solution sol;
    vector<int> result = sol.spiralOrder(matrix);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ", ";
    }
    cout << endl;

    return 0;
}