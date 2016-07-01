#include "../include/header.h"


/*
For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
*/


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        int start = 0, end = 0;
        int sum = 0;
        int step = size + 1;

        while(start < size && end < size)
        {
            while(sum < s && end < size)
            {
                sum += nums[end++]; // end may > size - 1
            }

            while(sum >= s && start < size)
            {
                step = min(end - start, step);
                sum -= nums[start++];
            }
        }

        if(size + 1 == step)
        {
            return 0;
        }

        return step;
    }
};

int main()
{
    int s = 80;
    vector<int> input = {10,5,13,4,8,4,5,11,14,9,16,10,20,8};
    Solution sol;
    int result = sol.minSubArrayLen(s, input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
