#include "../include/header.h"

/*
Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
*/


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ret;
        if(0 == nums.size())
        {
            return ret;
        }

        sort(nums.begin(), nums.end());

        int last = nums[0];
        int cnt = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(1 == cnt % 2 && last != nums[i])
            {
                ret.push_back(last);
                cnt = 1;
            }
            else
            {
                ++cnt;
            }
            last = nums[i];
        }

        if(1 == cnt % 2)
        {
            ret.push_back(last);
        }

        return ret;
    }
};

int main()
{
    vector<int> input = {1, 2, 1, 3, 2, 5};
    Solution sol;
    vector<int> result = sol.singleNumber(input);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ", ";
    }
    cout << endl;

    return 0;
}
