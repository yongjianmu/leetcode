#include "../include/header.h"

/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.
For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        int size = nums.size();
        if(3 > size)
        {
            return ret;
        }

        sort(nums.begin(), nums.end());
        if(nums[0] > 0 || nums[size - 1] < 0)
        {
            return ret;
        }

        int pos = 0;
        while(nums[pos] <= 0)
        {
            while(0 < pos && size - 2 > pos && nums[pos] == nums[pos - 1])
            {
                ++pos;
            }

            int start = pos + 1, end = size - 1;
            while(start < end)
            {
                int value = nums[pos] + nums[start] + nums[end];
                if(0 == value)
                {
                    vector<int> cur;
                    cur.push_back(nums[pos]);
                    cur.push_back(nums[start]);
                    cur.push_back(nums[end]);
                    ret.push_back(cur);
                    ++start;
                    while(start > pos + 1 && start < end && nums[start] == nums[start - 1])
                    {
                        ++start;
                    }
                    --end;
                    while(end < size - 1 && start < end && nums[end] == nums[end + 1])
                    {
                        --end;
                    }
                }
                else if(0 > value)
                {
                    ++start;
                    while(start > pos + 1 && start < end && nums[start] == nums[start - 1])
                    {
                        ++start;
                    }
                }
                else
                {
                    --end;
                    while(end < size - 1 && start < end && nums[end] == nums[end + 1])
                    {
                        --end;
                    }
                }
            }
            ++pos;
        }

        return ret;
    }
};

int main() {
    //vector<int> input = {-1, 0, 1, 2, -1, -4};
    //vector<int> input = {0, 0, 0};
    vector<int> input = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    Solution sol;
    vector<vector<int> > result = sol.threeSum(input);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        for(int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}