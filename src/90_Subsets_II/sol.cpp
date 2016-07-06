#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;


/*
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    unordered_map<string, bool> mp;
    void solve(int curr, int size, vector<int>& nums, vector<vector<int> >& ret, vector<int>& res)
    {
        string s = "";
        for(int i = 0; i < res.size(); ++i)
        {
            string tmp;
            stringstream ss;
            ss << res[i];
            ss >> tmp;
            s += tmp;
        }
        if(mp.find(s) == mp.end())
        {
            ret.push_back(res);
            mp[s] = true;
        }

        for(int i = curr; i < size; ++i)
        {
            res.push_back(nums[i]);
            solve(i + 1, size, nums, ret, res);
            res.pop_back();
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ret;
        vector<int> res;

        solve(0, nums.size(), nums, ret, res);
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
    vector<vector<int> > result = sol.subsetsWithDup(input);

    cout << "##### Result #####" << endl;
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
