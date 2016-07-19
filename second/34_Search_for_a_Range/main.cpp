#include "../include/header.h"

/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        int size = nums.size();
        if(0 == size)
        {
            return ret;
        }

        int start = 0, end = size - 1, pos = -1;
        while(start <= end)
        {
            int mid = start + ((end - start) >> 1);
            if(nums[mid] == target)
            {
                pos = mid;
                break;
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

        if(pos != -1)
        {
            start = pos, end = pos;
            while(true)
            {
                if((start <= 0 || nums[start - 1]!= nums[start]) && (end >= size - 1 || nums[end] != nums[end + 1]))
                {
                    break;
                }

                if(start > 0 && nums[start - 1] == nums[start])
                {
                    --start;
                }
                if(end < size - 1 && nums[end] == nums[end + 1])
                {
                    ++end;
                }
            }
            ret[0] = start;
            ret[1] = end;
        }
        return ret;
    }
};


int main() {
    vector<int> input = {5, 7, 7, 8, 8, 10};
    int target = 8;
    Solution sol;
    vector<int> result = sol.searchRange(input, target);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ", ";
    }
    cout << endl;

    return 0;
}