#include "../include/header.h"


/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
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
    vector<vector<int> > mRet;

    void solve(int start, int size, vector<int>& cur, vector<int>& nums)
    {
        if(find(mRet.begin(), mRet.end(), cur) == mRet.end())
        {
            mRet.push_back(cur);
        }

        if(start >= size)
        {
            return;
        }

        for(int i = start; i < size; ++i)
        {
            cur.push_back(nums[i]);
            solve(i + 1, size, cur, nums);
            cur.pop_back();
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        int size = nums.size();
        if(0 == size)
        {
            return mRet;
        }

        sort(nums.begin(), nums.end());
        int start = 0;
        vector<int> cur;
        solve(start, size, cur, nums);
        return mRet;
    }
};

int main()
{
    vector<int> input = {4, 4, 4, 1, 4};
    Solution sol;
    vector<vector<int> > result = sol.subsetsWithDup(input);
    printResult();
    printVector2D(result);

    return 0;
}
