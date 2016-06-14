#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        int row = matrix.size();
        if(0 == row)
        {
            return;
        }

        int col = matrix[0].size();
        if(0 == col)
        {
            return;
        }

        unordered_map<int, int> row_map, col_map;
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(0 == matrix[i][j])
                {
                    row_map[i] = 1;
                    col_map[j] = 1;
                }
            }
        }

        unordered_map<int, int>::iterator iter;
        for(iter = row_map.begin(); iter != row_map.end(); ++iter)
        {
            for(int j = 0; j < col; ++j)
            {
                matrix[iter->first][j] = 0;
            }
        }
        for(iter = col_map.begin(); iter != col_map.end(); ++iter)
        {
            for(int i = 0; i < row; ++i)
            {
                matrix[i][iter->first] = 0;
            }
        }
    }
};

int main()
{
    vector<int> row1;
    row1.push_back(1);
    row1.push_back(0);
    row1.push_back(1);

    vector<int> row2;
    row2.push_back(1);
    row2.push_back(1);
    row2.push_back(1);

    vector<int> row3;
    row3.push_back(1);
    row3.push_back(1);
    row3.push_back(1);

    vector<vector<int> > matrix;
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);

    Solution sol;
    sol.setZeroes(matrix);

    for(int i = 0; i < matrix.size(); ++i)
    {
        for(int j = 0; j < matrix[0].size(); ++j)
        {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}
