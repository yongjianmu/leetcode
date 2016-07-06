#include "../include/header.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto iter = nums.begin(); iter != nums.end(); ++iter)
        {
            if(mp.find(*iter) != mp.end())
            {
                if(distance(nums.begin(), iter) - mp[*iter] <= k)
                {
                    cout << distance(nums.begin(), iter) << endl;
                    return true;
                }
            }
            mp[*iter] = distance(nums.begin(), iter);
        }
        return false;
    }
};

int main()
{
    vector<int> input = {1, 2, 1};
    int k = 0;
    Solution sol;
    bool result = sol.containsNearbyDuplicate(input, k);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
