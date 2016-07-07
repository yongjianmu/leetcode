#include "../include/header.h"

/*
Given[10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is[2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (0 == size)
        {
            return 0;
        }

        int ret = 1;
        vector<int> dp(size, 0);
        dp[0] = 1;
        for (int i = 1; i < size; ++i)
        {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; --j)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            cout << i << ", " << dp[i] << endl;
            ret = max(ret, dp[i]);
        }
        
        return ret;
    }
};

int main()
{
    vector<int> input = { 1,3,6,7,9,4,10,5,6 };
    Solution sol;
    int result = sol.lengthOfLIS(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}