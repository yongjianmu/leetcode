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

    int minimumTotal(vector<vector<int> >& triangle) {
        int row = triangle.size();
        if(0 == row)
        {
            return 0;
        }
        else if(1 == row)
        {
            return triangle[0][0];
        }

        int ret = INT_MAX;
        for(int i = 1; i < row; ++i)
        {
            int col = triangle[i].size();
            for(int j = 0; j < col; ++j)
            {
                if(j == col - 1)
                {
                    triangle[i][j] += triangle[i - 1][j - 1];
                }
                else if(0 == j)
                {
                    triangle[i][j] += triangle[i - 1][j];
                }
                else
                {
                    triangle[i][j] = min(triangle[i][j] + triangle[i - 1][j - 1], triangle[i][j] + triangle[i - 1][j]);
                }
                if(row - 1 == i)
                {
                    ret = min(ret, triangle[i][j]);
                }
            }
        }
        return ret;
    }
};

int main()
{
    vector<vector<int> > input = {
        {1},
        {2, 3},
        //{6, 5, 7},
        //{4, -21, 8, 3}
    };
    Solution sol;
    int result = sol.minimumTotal(input);
    printResult();
    cout << result << endl;
    return 0;
}
