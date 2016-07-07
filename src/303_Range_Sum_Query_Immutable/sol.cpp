#include "../include/header.h"

/*
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
*/


class NumArray {
public:
    vector<int> mDp;
    vector<int> mNums;
    int mSize;

    NumArray(vector<int> &nums) {
        mSize = nums.size();
        if (0 == mSize)
        {
            return;
        }

        mDp.push_back(nums[0]);
        mNums.push_back(nums[0]);
        for (int i = 1; i < mSize; ++i)
        {
            mDp.push_back(nums[i] + mDp[i - 1]);
            mNums.push_back(nums[i]);
        }
    }

    int sumRange(int i, int j) {
        if (i >= mSize || j >= mSize)
        {
            return 0;
        }

        return mDp[j] - mDp[i] + mNums[i];
    }
};


// Your NumArray object will be instantiated and called as such:
int main()
{
    vector<int> nums = { -2, 0, 3, -5, 2, -1 };
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    cout << numArray.sumRange(2, 5) << endl;
    cout << numArray.sumRange(0, 5) << endl;

    return 0;
}
