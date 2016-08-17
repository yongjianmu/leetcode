#include "../include/header.h"

/*
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.
*/

class Solution {
public:
    int mRet;
    vector<pair<int, int> > mVec;

    void check(int start, int end, vector<long long> sum, vector<int> nums, int lower, int upper)
    {
        if(start > end)
        {
            return;
        }

        long long value = sum[end] - sum[start] + nums[start];
        if(lower <= value && upper >= value)
        {
            pair<int, int> p = make_pair(start, end);
            if(find(mVec.begin(), mVec.end(), p) == mVec.end())
            {
                ++mRet;
                mVec.push_back(p);
            }
            //cout << start << ", " << end << endl;
        }

        check(start + 1, end, sum, nums, lower, upper);
        check(start, end - 1, sum, nums, lower, upper);
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        mRet = 0;
        int size = nums.size();
        if(0 == size)
        {
            return 0;
        }

        vector<long long> sum(size, LONG_MAX);
        sum[0] = nums[0];
        for(int i = 1; i < size; ++i)
        {
            sum[i] = sum[i - 1] + nums[i];
        }

        check(0, size - 1, sum, nums, lower, upper);
        return mRet;
    }
};

int main()
{
    vector<int> input = {2147483647, -2147483648, -1, 0};
    Solution sol;
    int result = sol.countRangeSum(input, -1, 0);
    printResult();
    cout << result << endl;

    return 0;
}
