#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if(0 == size)
        {
            return 0;
        }

        int max_sum = nums[0];
        int sum = nums[0];

        if(1 == size)
        {
            return max_sum;
        }

        for(int i = 1; i < size; ++i)
        {
            if(sum > 0)
            {
                sum += nums[i];
            }
            else
            {
                sum = nums[i];
            }

            max_sum = max(sum, max_sum);
        }

        return max_sum;
    }
};
