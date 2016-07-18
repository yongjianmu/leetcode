#include "../include/header.h"

/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
 */

class Solution {
public:

    int binarySearch(int start, int end, int target, vector<int>& nums)
    {
        while(start <= end)
        {
            int mid = start + ((end - start) >> 1);
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(0 == size)
        {
            return -1;
        }

        int start = 0, end = size - 1;
        while(start <= end)
        {
            cout << start << ", " << end << endl;
            int mid = start + ((end - start) >> 1);

            if(nums[mid] == target)
            {
                return mid;
            }

            if(mid > start && nums[start] <= nums[mid - 1] && nums[start] <= target && nums[mid - 1] >= target)
            {
                cout << 1 << endl;
                return binarySearch(start, mid - 1, target, nums);
            }

            if(mid < end && nums[end] >= nums[mid + 1] && nums[mid + 1] <= target && nums[end] >= target)
            {
                cout << 2 << endl;
                return binarySearch(mid + 1, end, target, nums);
            }

            if(nums[start] < nums[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> input = {1};
    int target = 0;
    Solution sol;
    int result = sol.search(input, target);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}