#include "../include/header.h"


/*
Given [3, 1, 5, 8] 

Return 167 
    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int ret = 0;
        if(0 == nums.size())
        {
            return 0;
        }
        else if(1 == nums.size())
        {
            return nums[0];
        }

        vector<int>::iterator iter;
        while(3 <= nums.size())
        {
            int pos = 1;
            int value = nums[1];
            for(int i = 2; i < nums.size() - 1; ++i)
            {
                if(value > nums[i])
                {
                    pos = i;
                    value = nums[i];
                }
            }

            // burst this one
            cout << pos <<", " << nums[pos] << ", " << nums[pos - 1] * nums[pos] * nums[pos + 1] << endl;
            ret += nums[pos - 1] * nums[pos] * nums[pos + 1];
            iter = nums.begin();
            advance(iter, pos);
            nums.erase(iter);
        }

        // left two
        ret += nums[0] * nums[1] + max(nums[0], nums[1]);

        return ret;
    }
};

int main()
{
    vector<int> input = {9,76,64,21,97,60};
    Solution sol;
    int result = sol.maxCoins(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
