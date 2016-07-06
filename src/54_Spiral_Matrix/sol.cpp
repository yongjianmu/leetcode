#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ans;
		if (matrix.size() == 0) return  ans;
		int m = matrix.size(),n=matrix[0].size();
		int row =(m >> 1 )+1 ,cnt=0 ,tot=n*m;
		for (int k = 0; k < row; k++)
		{
			for (int i = k; i < n - k && cnt<tot; i++,cnt++)		
				ans.push_back(matrix[k][i]);							
			for (int i = k + 1; i < m - k && cnt<tot; i++, cnt++)
				ans.push_back(matrix[i][n - k - 1]);
			for (int i = n - k - 2; i >= k &&cnt<tot; i--, cnt++)
				ans.push_back(matrix[m - k - 1][i]);
			for (int i = m - k - 2; i > k && cnt<tot; i--, cnt++)
				ans.push_back(matrix[i][k]);
		}
		return ans;
    }
};

int main()
{
    vector<vector<int> > matrix;
    vector<int> row1;
    vector<int> row2;
    vector<int> row3;

    row1.push_back(1);
    row1.push_back(2);
    row1.push_back(3);

    row2.push_back(4);
    row2.push_back(5);
    row2.push_back(6);

    row3.push_back(7);
    row3.push_back(8);
    row3.push_back(9);

    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);

    Solution sol;
    vector<int> result = sol.spiralOrder(matrix);
    
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << "; ";
    }
    cout << endl;

    return 0;
}
