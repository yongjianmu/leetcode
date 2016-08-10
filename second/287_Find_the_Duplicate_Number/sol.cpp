#include "../include/header.h"

/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = size - 1;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            int sum = 0;
            for(int i = 0; i < size; ++i)
            {
                if(nums[i] <= mid)
                {
                    ++sum;
                }
            }

            if(sum <= mid)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};


int main()
{
    vector<int> input = {1, 3, 4, 2, 2};
    Solution sol;
    int result = sol.findDuplicate(input);
    printResult();
    cout << result << endl;

    return 0;
}
