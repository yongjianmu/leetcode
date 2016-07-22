#include "../include/header.h"

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
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

        int x = 0, y = col - 1;
        while(x < row && y >= 0)
        {
            if(matrix[x][y] == target)
            {
                return true;
            }
            else if(matrix[x][y] > target)
            {
                --y;
            }
            else
            {
                ++x;
            }
        }
        return false;
    }
};
