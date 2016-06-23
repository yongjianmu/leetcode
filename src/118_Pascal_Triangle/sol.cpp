#include <vector>
#include <iostream>

using namespace std;

/*
For example, given numRows = 5,
    Return

    [
    [1],
    [1,1],
    [1,2,1],
    [1,3,3,1],
    [1,4,6,4,1]
    ]
*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        for(int i = 0; i < numRows; ++i)
        {
            vector<int> row;
            for(int j = 0; j <= i; ++j)
            {
                if(0 == j || i == j)
                {
                    row.push_back(1);
                }
                else
                {
                    row.push_back(ret[i - 1][j] + ret[i - 1][j - 1]);
                }
            }
            ret.push_back(row);
        }
        return ret;
    }
};

int main()
{
    int row = 5;
    Solution sol;
    vector<vector<int> > result = sol.generate(row);
    for(int i = 0; i < result.size(); ++i)
    {
        for(int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}
