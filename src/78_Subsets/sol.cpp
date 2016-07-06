#include <vector>
#include <iostream>

using namespace std;

/*
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:

    void rec(int start, vector<int>& nums, vector<int>& pre, vector<vector<int> >& ret)
    {
        if(pre.size() <= nums.size())
        {
            ret.push_back(pre);
        }

        for(int i = start; i < nums.size() ; ++i)
        {
            pre.push_back(nums[i]);
            rec(i + 1, nums, pre, ret);
            pre.pop_back();
        }
    }

    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > ret;
        if(0 == nums.size())
        {
            return ret;
        }
        
        vector<int> pre;
        rec(0, nums, pre, ret);
        return ret;
    }
};

int main()
{
    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    Solution sol;
    vector<vector<int> > result = sol.subsets(input);
    cout << "**** Result ****" << endl;
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
