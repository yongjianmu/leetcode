#include "../include/header.h"

/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/

class Solution {
public:

    void setZeroes(vector<vector<int> >& matrix) {
        int m = matrix.size(), n = matrix[0].size();
		bool flag = false;
		for (int i = 0; i < m; i++){
			if (!matrix[i][0]) flag = true;
			for (int j = 1; j < n; j++){
				if (matrix[i][j] == 0){
					matrix[0][j] = matrix[i][0] = 0;
				}
			}
		}
		for (int i = m - 1; i >= 0; i--){
			for (int j = n - 1; j >= 1; j--)
				if (!matrix[i][0] || !matrix[0][j])
					matrix[i][j] = 0;
			if (flag) matrix[i][0] = 0;
		}
    }
};

int main()
{
    vector<vector<int> > matrix = {
        {0, 0, 0, 5},
        {4, 3, 1, 4},
        {0, 1, 1, 4},
        {1, 2, 1, 3},
        {0, 0, 1, 1}
    };
    Solution sol;
    sol.setZeroes(matrix);
    printVector2D(matrix, false);

    return 0;
}
