#include <iostream>
#include <vector>

using namespace std;

/*
   [
   [1,   3,  5,  7],
   [10, 11, 16, 20],
   [23, 30, 34, 50]
   ]
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

            if(matrix[0][0] > target || matrix[row - 1][col - 1] < target)
            {
                return false;
            }

            int rowL = 0, rowR = row - 1;
            int retRow = 0;
            while(rowL <= rowR)
            {
                int mid = (rowL + rowR) >> 1;
                if(matrix[mid][col - 1] < target)
                {
                    if(row - 1 == mid)
                    {
                        retRow = mid;
                        break;
                    }

                    if(matrix[mid + 1][col - 1] >= target)
                    {
                        retRow = mid + 1;
                        break;
                    }
                    else
                    {
                        rowL = mid + 1;
                    }
                }
                else if(matrix[mid][col - 1] > target)
                {
                    if(0 == mid || matrix[mid][0] <= target)
                    {
                        retRow = mid;
                        break;
                    }

                    if(matrix[mid - 1][col - 1] <= target)
                    {
                        retRow = mid - 1;
                        break;
                    }
                    else
                    {
                        rowR = mid - 1;
                    }
                }
                else
                {
                    return true;
                }
            }

            int colL = 0, colR = col - 1;
            while(colL <= colR)
            {
                int mid = (colL + colR) >> 1;
                if(matrix[retRow][mid] < target)
                {
                    colL = mid + 1;
                }
                else if(matrix[retRow][mid] > target)
                {
                    colR = mid - 1;
                }
                else
                {
                    return true;
                }
            }

            return false;
        }
};

int main()
{
    vector<int> row1;
    row1.push_back(1);
    row1.push_back(3);
    row1.push_back(5);
    row1.push_back(7);

    vector<int> row2;
    row2.push_back(10);
    row2.push_back(11);
    row2.push_back(16);
    row2.push_back(20);

    vector<int> row3;
    row3.push_back(23);
    row3.push_back(30);
    row3.push_back(34);
    row3.push_back(50);

    vector<vector<int> > matrix;
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);

    int target = 10;
    Solution sol;
    cout << sol.searchMatrix(matrix, target) << endl;

    return 0;
}
