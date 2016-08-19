#include "../include/header.h"

/*
   Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

   If there are multiple solutions, return any subset is fine.

   Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)
Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        if (nums.empty()) return ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), index(n, -1);
        int max_index=0, max_dp=1;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >=0 ; j--) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    index[i] = j;
                }
            }
            if (max_dp < dp[i]) {
                max_dp = dp[i];
                max_index = i;
            }
        }
        for (int i = max_index; i != -1; i = index[i])
          ans.push_back(nums[i]);
        return ans;
    }
};

int main()
{
    return 0;
}
