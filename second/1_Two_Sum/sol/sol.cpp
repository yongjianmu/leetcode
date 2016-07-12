#include "stdafx.h"
#include "../../include/header.h"

/*
Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].



UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.



Subscribe to see which companies asked this question
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
    	unordered_map<int, int> mp1;
        for (int i = 0; i < nums.size(); ++i)
        {
            mp1[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (mp1.find(target - nums[i]) != mp1.end())
            {
                if(i < mp1[target - nums[i]])
                {
                    ret.push_back(i);
                    ret.push_back(mp1[target - nums[i]]);
                }
                
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> input = {2, 7, 5, 11};
    int target = 9;
    Solution sol;
    vector<int> result = sol.twoSum(input, target);
	cout << "#### Result ####" << endl;
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ", ";
    }
    cout << endl;

	return 0;
}



