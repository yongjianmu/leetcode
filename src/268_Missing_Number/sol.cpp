#include "../include/header.h"

/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int last = -1;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(last + 1 != nums[i])
            {
                return last + 1;
            }
            last = nums[i];
        }

        return last + 1;
    }
};
