#include "../include/header.h"

/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/


class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if(1 == size)
        {
            return nums[0];
        }

        int start = 0, end = size - 1;
        if(nums[start] < nums[end])
        {
            return nums[start];
        }

        while(start < end)
        {
            if(start + 1 == end)
            {
                return min(nums[start], nums[end]);
            }

            int mid = start + ((end - start) >> 1);
            if(nums[mid] > nums[start])
            {
                start = mid;
            }
            else if(nums[mid])
            {
                end = mid;
            }
        }

        return nums[0];
    }
};

int main()
{
    vector<int> input = {1, 2, 3};
    Solution sol;
    int result = sol.findMin(input);
    printResult();
    cout << result << endl;

    return 0;
}
