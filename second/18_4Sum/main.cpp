#include "../include/header.h"

/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
 */

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ret;
        int size = nums.size();
        if(4 > size)
        {
            return ret;
        }

        sort(nums.begin(), nums.end());
        int pos1 = 0;
        while(pos1 < size - 3)
        {
            int pos2 = pos1 + 1;
            while(pos2 < size - 2)
            {
                int pos3 = pos2 + 1, pos4 = size - 1;
                while(pos3 < pos4)
                {
                    int value = nums[pos1] + nums[pos2] + nums[pos3] + nums[pos4];
                    if(target == value)
                    {
                        vector<int> cur;
                        cur.push_back(nums[pos1]);
                        cur.push_back(nums[pos2]);
                        cur.push_back(nums[pos3]);
                        cur.push_back(nums[pos4]);
                        ret.push_back(cur);

                        ++pos3;
                        while(pos3 < size - 1 && pos3 < pos4 && nums[pos3] == nums[pos3 - 1])
                        {
                            ++pos3;
                        }
                        --pos4;
                        while(pos4 < size - 1 && pos3 < pos4 && nums[pos4] == nums[pos4 + 1])
                        {
                            --pos4;
                        }
                    }
                    else if(target < value)
                    {
                        --pos4;
                        while(pos4 < size - 1 && pos3 < pos4 && nums[pos4] == nums[pos4 + 1])
                        {
                            --pos4;
                        }
                    }
                    else
                    {
                        ++pos3;
                        while(pos3 < size - 1 && pos3 < pos4 && nums[pos3] == nums[pos3 - 1])
                        {
                            ++pos3;
                        }
                    }
                }
                ++pos2;
                while(nums[pos2] == nums[pos2 - 1] && pos2 < size - 2)
                {
                    ++pos2;
                }
            }
            ++pos1;
            while(nums[pos1] == nums[pos1 - 1] && pos1 < size - 3)
            {
                ++pos1;
            }
        }
        return ret;
    }
};

int main() {
    vector<int> input = {1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution sol;
    vector<vector<int> > result = sol.fourSum(input, target);
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