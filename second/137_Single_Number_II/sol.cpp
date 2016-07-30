#include "../include/header.h"

/*
Given an array of integers, every element appears twice except for one. Find that single one.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0x0;
        int bit[32] = {0};
        for(int i = 0; i < 32; ++i)
        {
            for(int j = 0; j < nums.size(); ++j)
            {
                bit[i] += (nums[j] >> i) & 0x1;
            }
            ret |= (bit[i] % 3) << i;
        }
        return ret;
    }
};
