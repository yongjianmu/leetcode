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

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        mRet = 0;
        int size = nums.size();
        if(0 == size)
        {
            return 0;
        }


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
