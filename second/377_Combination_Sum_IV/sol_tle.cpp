#include "../include/header.h"

/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
*/

class Solution {
public:
    int mRet;

    void solve(vector<int> nums, int size, int target, int cur)
    {
        for(int i = 0; i < size; ++i)
        {
            if(nums[i] + cur == target)
            {
                ++mRet;
            }
            else if(nums[i] + cur < target)
            {
                solve(nums, size, target, cur + nums[i]);
            }
        }
    }

    int combinationSum4(vector<int>& nums, int target) {
        mRet = 0;
        int size = nums.size();
        if(0 == size)
        {
            return mRet;
        }

        solve(nums, size, target, 0);
        return mRet;
    }
};

int main()
{
    vector<int> input = {1, 2, 3};
    int target = 4;
    Solution sol;
    int result = sol.combinationSum4(input, target);
    printResult();
    cout << result << endl;

}
