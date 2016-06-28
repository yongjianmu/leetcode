#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();
        if(2 > size)
        {
            return 0;
        }

        sort(nums.begin(), nums.end());
        int ret = 0;
        for(int i = 1; i < size; ++i)
        {
            ret = max(ret, nums[i] - nums[i - 1]);
        }

        return ret;
    }
};
