#include "../include/header.h"

/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        int size = nums.size();
        if(0 == size)
        {
            return ret;
        }
        else if(1 == size)
        {
            ret.push_back(nums[0]);
            return ret;
        }

        sort(nums.begin(), nums.end());
        int threshold = size / 3;
        int last = nums[0];
        int cnt = 1;
        for(int i = 1; i < size; ++i)
        {
            if(last != nums[i])
            {
                if(cnt > threshold)
                {
                    ret.push_back(last);
                }
                last = nums[i];
                cnt = 1;
                if(i == size - 1)
                {
                    if(cnt > threshold)
                    {
                        ret.push_back(last);
                    }
                }
            }
            else
            {
                ++cnt;
                if(i == size - 1)
                {
                    if(cnt > threshold)
                    {
                        ret.push_back(last);
                    }
                }
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> input = {1, 2};
    Solution sol;
    vector<int> result = sol.majorityElement(input);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ", ";
    }
    cout << endl;

    return 0;
}
