#include "../include/header.h"


/*
 Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

 Solve it without division and in O(n).

 For example, given [1,2,3,4], return [24,12,8,6]
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret;
        int size = nums.size();
        unordered_map<int, int> mp;
        long long product = 1;
        for(int i = 0; i < size; ++i)
        {
            if(0 == nums[i])
            {
                mp[i] = 0;
            }
            else
            {
                product *= nums[i];
            }
        }

        for(int i = 0; i < size; ++i)
        {
            if(mp.size() == 1)
            {
                if(mp.find(i) != mp.end())
                {
                    ret.push_back(static_cast<int> (product));
                }
                else
                {
                    ret.push_back(0);
                }
            }
            else if(mp.size() > 1)
            {
                ret.push_back(0);
            }
            else if(mp.size() == 0)
            {
                int cur = 0;
                if(0 != nums[i])
                {
                    cur = static_cast<int> (product / nums[i]);
                }
                ret.push_back(cur);
            }
        }

        return ret;
    }
};

int main()
{
    //vector<int> input = {1, 2, 3, 4};
    vector<int> input = {1, 0};
    Solution sol;
    vector<int> result = sol.productExceptSelf(input);
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ", ";
    }
    cout << endl;

    return 0;
}
