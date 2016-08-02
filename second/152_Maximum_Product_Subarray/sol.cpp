#include "../include/header.h"


/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if(0 == size)
        {
            return 0;
        }

        int max_value = nums[0], min_value = nums[0], ret = nums[0];
        for(int i = 1; i < size; ++i)
        {
            int tmp_max = max_value * nums[i], tmp_min = min_value * nums[i];
            max_value = max(tmp_max, tmp_min);
            min_value = min(tmp_max, tmp_min);
            max_value = max(max_value, nums[i]);
            min_value = min(min_value, nums[i]);
            ret = max(ret, max_value);
        }
        return ret;
    }
};
