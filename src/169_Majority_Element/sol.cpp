#include "../include/header.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> mp;
        unordered_map<int, int>::iterator iter;
        int max_key, max_value;

        for(int i = 0; i < size; ++i)
        {
            ++mp[nums[i]];
        }

        max_value = INT_MIN;
        for(iter = mp.begin(); iter != mp.end(); ++iter)
        {
            if(max_value < iter->second)
            {
                max_value = iter->second;
                max_key = iter->first;
            }
        }

        return max_key;
    }
};

int main()
{
    vector<int> input = {1, 2, 3, 4, 2, 2, 2};
    Solution sol;
    cout << sol.majorityElement(input) << endl;

    return 0;
}
