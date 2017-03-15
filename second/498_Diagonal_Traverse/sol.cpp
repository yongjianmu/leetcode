#include "../include/header.h"

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int row = matrix.size();
        if(0 == row) return ret;
        int col = matrix[0].size();
        if(0 == col) return ret;
        ret.resize(row * col);
        
        bool dir = true; // true: up, false: down
        int i = 0, j = 0, cnt = 0;
        while(cnt < row * col)
        {
            ret[cnt++] = matrix[i][j];
            if(dir)
            {
                if(i == row - 1 && j == col - 1)
                {break;}
                else if(j == col - 1)
                {++i; dir = false;}
                else if(i == 0)
                {++j; dir = false;}
                else
                {--i; ++j;}
            }
            else
            {
                if(i == row - 1)
                {++j; dir = true;}
                else if(j == 0)
                {++i; dir = true;}
                else
                {++i; --j;}
            }
        }
        return ret;
    }
};

int main()
{
    vector<vector<int> > input = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    Solution sol;
    vector<int> ret = sol.findDiagonalOrder(input);
    printResult();
    printVector1D(ret);

    return 0;
}
