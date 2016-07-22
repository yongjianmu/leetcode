#include "../incluce/header.h"

class Solution {
public:
    void solve(int pos, int size, vector<int>& cur, vector<int>& nums, vector<vector<int> >& ret)
    {
        ret.push_back(cur);

        for(int i = pos; i < size; ++i)
        {
            cur.push_back(nums[i]);
            solve(i + 1, size, cur, nums, ret);
            cur.pop_back();
        }
    }

    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > ret;
        int size = nums.size();
        if(0 == size)
        {
            return ret;
        }

        //sort(nums.begin(), nums.end());
        vector<int> cur;
        solve(0, size, cur, nums, ret);

        return ret;
    }
};
