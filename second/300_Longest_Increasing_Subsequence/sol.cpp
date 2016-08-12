#include "../include/header.h"

/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
*/

class Solution {
public:

    int calcLen(int start, int end, int x, vector<int> g)
    {
        while(start < end)
        {
            int mid = start + ((end - start) >> 1);
            if(g[mid] < x)
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
        return start;
    }

    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(1 >= size)
        {
            return size;
        }

        vector<int> dp(size, 1), g(size + 1, INT_MAX);
        for(int i = 0; i < size; ++i)
        {
            int k = calcLen(1, size + 1, nums[i], g);
            dp[i] = k;
            g[k] = nums[i];
        }

        int ret = 1;
        for(int i = 1; i < size; ++i)
        {
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

int main()
{
    vector<int> input = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution sol;
    int result = sol.lengthOfLIS(input);
    printResult();
    cout << result << endl;

    return 0;
}
