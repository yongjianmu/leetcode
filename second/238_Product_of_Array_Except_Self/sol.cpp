#include "../include/header.h"

/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ret (size, 1);
        int i = 1, tmp = 1;

        for(i = 1; i < size; ++i)
        {
            ret[i] = ret[i - 1] * nums[i - 1];
        }

        for(i = size - 1; i >= 0; --i)
        {
            ret[i] *= tmp;
            tmp *= nums[i];
        }
        return ret;
    }
};
