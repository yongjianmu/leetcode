#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int> &nums, int target, bool maxIndex)
    {
        int L = 0, R = nums.size();
        while(L < R)
        {
            int mid = L + (R - L) / 2;
            if(nums[mid] < target)
            {
                L = mid + 1;
            }
            else if(nums[mid] > target)
            {
                R = mid;
            }
            else if(maxIndex)
            {
                L = mid + 1;
            }
            else
            {
                R = mid;
            }
        }
        return L;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        int L = binarySearch(nums, target, false);
        if(L < nums.size() && nums[L] == target)
        {
            v.push_back(L);
            v.push_back(binarySearch(nums, target, true) - 1);
        }
        else
        {
            v.push_back(-1);
            v.push_back(-1);
        }
        return v;
    }
};
