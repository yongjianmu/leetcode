#include "../include/header.h"

/*
 Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

Given target = 5, return true.

Given target = 20, return false.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int row = matrix.size();
        if(0 == row)
        {
            return false;
        }

        int col = matrix[0].size();
        if(0 == col)
        {
            return false;
        }

        for(int i = 0; i < row; ++i)
        {
            if(matrix[i][0] <= target && matrix[i][col - 1] >= target)
            {
                for(int j = 0; j < col; ++j)
                {
                    if(target == matrix[i][j])
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int> > input = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 24;

    Solution sol;
    bool result = sol.searchMatrix(input, target);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
