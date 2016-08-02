#include "../include/header.h"


/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if(0 == size)
        {
            return 0;
        }

        int peak = nums[0], ret = 0;
        for(int i = 1; i < size; ++i)
        {
            if(nums[i] < nums[i - 1])
            {
                break;
            }
            peak = nums[i];
            ret = i;
        }

        return ret;
    }
};
