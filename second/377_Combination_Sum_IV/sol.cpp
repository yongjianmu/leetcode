#include "../include/header.h"

/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
*/

class Solution {
public:

    int combinationSum4(vector<int>& nums, int target) {
        int size = nums.size();
        if(0 == size)
        {
            return 0;
        }

        vector<int> res = vector<int>(target + 1, 0);
        res[0] = 1;
        for(int t = 1; t <= target; t++)    
        {
            for(int num: nums) 
            {
                if(t - num >= 0)
                {
                    res[t] += res[t - num];
                }
            }
        }

        return res[target];
    }
};

int main()
{
    vector<int> input = {1, 2, 3};
    int target = 4;
    Solution sol;
    int result = sol.combinationSum4(input, target);
    printResult();
    cout << result << endl;

}
