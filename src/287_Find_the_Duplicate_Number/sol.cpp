#include "../include/header.h"


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = size - 1;
        while(left <= right)
        {
            int mid = (left + right) >> 1;
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
