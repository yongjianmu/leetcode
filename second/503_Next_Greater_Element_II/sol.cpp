#include "../include/header.h"

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if(0 == n) return vector<int>(0);
        vector<int> ret(n, -1);
        stack<pair<int, int> > stk;
        for(int i = 0; i < n; ++i)
        {
            while(!stk.empty() && nums[i] > stk.top().first)
            {
                ret[stk.top().second] = nums[i];
                stk.pop();
            }
            stk.push({nums[i], i});
        }
        
        for(int i = 0; i < n; ++i)
        {
            while(nums[i] > stk.top().first)
            {
                ret[stk.top().second] = nums[i];
                stk.pop();
            }
        } 
        return ret;
    }
};

int main()
{
    vector<int> input = {1,2,1};
    Solution sol;
    vector<int> ret = sol.nextGreaterElements(input);
    printResult();
    printVector1D(ret);

    return 0;
}
