#include "../include/header.h"

/*
Given an unsorted integer array, find the first missing positive integer.

For example,
 Given [1,2,0] return 3,
 and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        if(0 == size)
        {
            return 1;
        }

        for(int i = 0; i < size; )
        {
            if(nums[i] > 0 && nums[i] <= size && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[nums[i] - 1], nums[i]);
            }
            else
            {
                ++i;
            }
        }

        for(int i = 0; i < size; ++i)
        {
            if(nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return size + 1;
    }
};

int main() {
    vector<int> input = {3, 4, -1, 1};
    Solution sol;
    int result = sol.firstMissingPositive(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}