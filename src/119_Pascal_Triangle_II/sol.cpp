#include <vector>
#include <iostream>
#include <algorithm>

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
    vector<int> getRow(int rowIndex) {
        vector<int> last;
        for(int i = 0; i <= rowIndex; ++i)
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
                    row.push_back(last[j] + last[j - 1]);
                }
            }
            swap(last, row);
        }
        return last;
    }
};

int main()
{
    int row = 3;
    Solution sol;
    vector<int> result = sol.getRow(row);
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ", ";
    }
    cout << endl;

    return 0;
}
