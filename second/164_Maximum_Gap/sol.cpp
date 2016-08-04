#include "../include/header.h"


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();
        if(2 > size)
        {
            return 0;
        }

        multiset<int> s;
        for(int i = 0; i < size; ++i)
        {
            s.insert(nums[i]);
        }

        int ret = INT_MIN;
        auto iter = s.begin();
        ++iter;
        for( ; iter != s.end(); ++iter)
        {
            auto it = iter;
            --it;
            int gap = abs(*iter - *it);
            ret = max(ret, gap);
        }
        
        return ret;
    }
};

int main()
{
    vector<int> input = {3, 6, 9, 1};
    Solution sol;
    int result = sol.maximumGap(input);
    printResult();
    cout << result << endl;

    return 0;
}
