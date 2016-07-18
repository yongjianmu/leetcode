#include "../include/header.h"

/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if(0 == size)
        {
            return 0;
        }

        int start = 0, end = size - 1, mid = 0;
        while(start <= end)
        {
            mid = start + ((end - start) >> 1);
            if(nums[mid] < target)
            {
                if(mid == size - 1)
                {
                    return size;
                }
                else if(nums[mid + 1] >= target)
                {
                    return mid + 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else if(nums[mid] > target)
            {
                if(mid == 0)
                {
                    return 0;
                }
                else if(nums[mid - 1] < target)
                {
                    return mid;
                }
                else if(nums[mid - 1] == target)
                {
                    return mid - 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            else
            {
                return mid;
            }
        }
    }
};

int main() {
    vector<int> input = {1, 3, 5};
    int target = 1;
    Solution sol;
    int result = sol.searchInsert(input, target);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}