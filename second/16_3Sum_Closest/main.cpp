#include "../include/header.h"

/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int ret = 0;
        int size = nums.size();
        if(0 == size)
        {
            return ret;
        }

        sort(nums.begin(), nums.end());

        int pos = 0;
        while(nums[pos] < size - 2)
        {
            while(0 < pos && size - 1 > pos && nums[pos] == nums[pos - 1])
            {
                ++pos;
            }

            int start = pos + 1, end = size - 1;
            while(start < end)
            {
                int value = nums[pos] + nums[start] + nums[end];
                int cur_diff = value - target;
                if(0 == cur_diff)
                {
                    return target;
                }
                else if(0 > cur_diff)
                {
                    ++start;
                    while(start > pos + 1 && start < end && nums[start] == nums[start - 1])
                    {
                        ++start;
                    }
                }
                else
                {
                    --end;
                    while(end < size - 1 && start < end && nums[end] == nums[end + 1])
                    {
                        --end;
                    }
                }

                if(abs(cur_diff) < diff)
                {
                    diff = abs(cur_diff);
                    ret = value;
                }
            }
            ++pos;
        }

        return ret;
    }
};

int main() {
    vector<int> input = {1, 1, 1, 0};
    int target = 100;
    Solution sol;
    int result = sol.threeSumClosest(input, target);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}