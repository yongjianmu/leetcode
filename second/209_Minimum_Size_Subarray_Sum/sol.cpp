#include "../include/header.h"


/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        if(0 == size)
        {
            return 0;
        }

        int ret = size + 1;
        int start = 0, end = 0;
        int value = nums[0];
        while(end < size)
        {
            if(value < s)
            {
                if(end < size - 1)
                {
                    ++end;
                    value += nums[end];
                }
                else
                {
                    break;
                }
            }
            else
            {
                ret = min(ret, end - start + 1);
                value -= nums[start];
                if(start < end)
                {
                    ++start;
                }
                else
                {
                    if(start >= size - 1)
                    {
                        break;
                    }
                    else
                    {
                        ++start;
                        end = start;
                        value = nums[start];
                    }
                }
            }
        }

        return ret == size + 1 ? 0 : ret;
    }
};

int main()
{
    vector<int> input = {2, 3, 1, 2, 4, 3};
    int s = 7;
    Solution sol;
    int result = sol.minSubArrayLen(s, input);
    printResult();
    cout << result << endl;

    return 0;
}
