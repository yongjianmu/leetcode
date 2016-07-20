#include "../include/header.h"

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if(1 >= size)
        {
            return true;
        }

        int last_achieve_pos = size - 1;
        for(int i = size - 2; i >= 0; --i)
        {
            if(i + nums[i] >= last_achieve_pos)
            {
                last_achieve_pos = i;
            }
        }
        return last_achieve_pos == 0;
    }
};

int main() {
    vector<int> input = {3, 2, 1, 0, 4};
    Solution sol;
    bool result = sol.canJump(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}