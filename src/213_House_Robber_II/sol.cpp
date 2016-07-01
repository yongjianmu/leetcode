#include "../include/header.h"

class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
        int size = end - start;
        if(0 == size)
        {
            return 0;
        }

        vector<int> dp(size, 0);
        dp[0] = nums[start];
        if(1 < size)
        {
            dp[1] = max(nums[start], nums[start + 1]);
        }
        else
        {
            return max(dp[0], 0);
        }

        for(int i = start + 2; i < end; ++i)
        {
            dp[i - start] = max(dp[i - 1 - start], dp[i - 2 - start] + nums[i]);
        }

        return max(dp[size - 1], 0);
    }

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

        return max(solve(nums, 0, size - 1), solve(nums, 1, size));
    }
};

int main()
{
    vector<int> input = {1, 2, 1, 1};
    Solution sol;
    int result = sol.rob(input);
    cout << result << endl;

    return 0;
}
