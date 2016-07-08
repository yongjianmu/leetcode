#include "../include/header.h"

/*
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
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

    void update(int i, int val) {
        if(i > mSize - 1)
        {
            return;
        }

        int diff = val - mNums[i];
        for(int j = i; j < mSize; ++j)
        {
            mDp[j] += diff;
        }
        mNums[i] = val;
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
    vector<int> nums = {1, 3, 5};
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    numArray.update(1, 2);
    cout << numArray.sumRange(0, 2) << endl;

    return 0;
}
