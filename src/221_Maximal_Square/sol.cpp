#include "../include/header.h"

/*
For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
*/

class Solution {
public:
    int mRow;
    int mCol;

    bool spread(vector<vector<char> >& matrix, int x, int y, int len) // len: the current length of side
    {
        if(x + len >= mRow || y + len >= mCol)
        {
            return false;
        }

        for(int i = x; i <= x +len; ++i)
        {
            if('0' == matrix[i][y + len])
            {
                return false;
            }
        }

        for(int i = y; i <= y +len; ++i)
        {
            if('0' == matrix[x + len][i])
            {
                return false;
            }
        }

        return true;
    }

    int maximalSquare(vector<vector<char> >& matrix) {
        mRow = matrix.size();
        if(0 == mRow)
        {
            return 0;
        }

        mCol = matrix[0].size();
        if(0 == mCol)
        {
            return 0;
        }

        int ret = 0;
        for(int i = 0; i < mRow; ++i)
        {
            for(int j = 0; j < mCol; ++j)
            {
                if('1' == matrix[i][j])
                {
                    int len = 1;
                    while(spread(matrix, i, j, len))
                    {
                        ++len;
                    }
                    ret = max(ret, len * len);
                }
            }
        }

        return ret;
    }
};

int main()
{
    vector<vector<char> > matrix;
    vector<char> row1 = {'1', '0', '1', '0', '0'};
    vector<char> row2 = {'1', '0', '1', '1', '1'};
    vector<char> row3 = {'1', '1', '1', '1', '1'};
    vector<char> row4 = {'1', '0', '0', '1', '0'};
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    matrix.push_back(row4);

    Solution sol;
    int result = sol.maximalSquare(matrix);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
