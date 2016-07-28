#include "../include/header.h"


/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/

class Solution {
public:
    int mRet;

    void solve(int row, int col, int value, int size, vector<vector<int> >& triangle)
    {
        if(size == row)
        {
            mRet = min(mRet, value + triangle[row][col]);
            return;
        }

        solve(row + 1, col, value + triangle[row][col], size, triangle);
        solve(row + 1, col + 1, value + triangle[row][col], size, triangle);
    }

    int minimumTotal(vector<vector<int> >& triangle) {
        int row = triangle.size();
        if(0 == row)
        {
            return 0;
        }

        mRet = INT_MAX;
        solve(0, 0, 0, row - 1, triangle);
        return mRet;
    }
};

int main()
{
    vector<vector<int> > input = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    Solution sol;
    int result = sol.minimumTotal(input);
    printResult();
    cout << result << endl;
    return 0;
}
