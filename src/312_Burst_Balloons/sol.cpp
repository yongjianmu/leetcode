#include "../include/header.h"


/*
Given [3, 1, 5, 8] 

Return 167 
    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
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

int main()
{
    vector<int> input = {9,76,64,21,97,60};
    Solution sol;
    int result = sol.maxCoins(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
