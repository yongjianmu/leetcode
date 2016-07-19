#include "../include/header.h"

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if(0 == size)
        {
            return 0;
        }
        int ret = nums[0];
        int cur = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            if(cur < 0)
            {
                cur = nums[i];
            }
            else
            {
                cur += nums[i];
            }
            ret = max(ret, cur);
        }
        return ret;
    }
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}