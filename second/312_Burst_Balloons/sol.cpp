#include "../include/header.h"

/*
   Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

   Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
*/

class Solution {
public:
    int DP(int i, int j, const vector<int> &nums, vector<vector<int> > &dp) {
        if (dp[i][j] > 0) return dp[i][j];
        for (int x = i; x <= j; x++) {
            int temp = DP(i, x - 1, nums, dp) + nums[i - 1] * nums[x] * nums[j + 1] + DP(x + 1, j, nums, dp);
            if (temp > dp[i][j]) dp[i][j] = temp;
        }
        return dp[i][j];
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int> > dp(n + 2, vector<int>(n + 2, 0));
        return DP(1, n, nums, dp);
    }
};
