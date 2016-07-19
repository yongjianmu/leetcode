#include "../include/header.h"

/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    vector<vector<int> > mRet;

    bool nextPermutation(vector<int>& nums, int size)
    {
        mRet.push_back(nums);
        int k = - 1;
        for(int i = size - 2; i >= 0; --i)
        {
            if(nums[i] < nums[i + 1])
            {
                k = i;
                break;
            }
        }

        if(-1 == k)
        {
            return false;
        }

        int l = size - 1;
        for(int i = size - 1; i > k; --i)
        {
            if(nums[i] > nums[k])
            {
                l = i;
                break;
            }
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());

        return true;
    }

    vector<vector<int> > permuteUnique(vector<int>& nums) {
        int size = nums.size();
        if(0 == size)
        {
            return mRet;
        }
        else if(1 == size)
        {
            mRet.push_back(nums);
            return mRet;
        }

        sort(nums.begin(), nums.end());
        while(true)
        {
            if(!nextPermutation(nums, size))
            {
                break;
            }
        }

        return mRet;
    }
};

int main() {
    vector<int> input = {2, 1, 1};
    Solution sol;
    vector<vector<int> > result = sol.permuteUnique(input);
    cout << "#### Result ####" << endl;
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
