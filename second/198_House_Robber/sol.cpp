#include "../include/header.h"


class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(0 == size)
        {
            return 0;
        }
        else if(1 == size)
        {
            return nums[0];
        }
        else if(2 == size)
        {
            return max(nums[0], nums[1]);
        }

        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < size; ++i)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[size - 1];
    }
};
