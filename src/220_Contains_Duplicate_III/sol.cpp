#include "../include/header.h"

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int size = nums.size();
        if(1 >= size)
        {
            return false;
        }

        set<int> window;
        int left = 0;
        for(int i = 0; i < size; ++i)
        {
            if(window.size() > k)
            {
                window.erase(nums[left++]);
            }

            auto iter = window.lower_bound(static_cast<long> (nums[i]) - static_cast<long> (t));
            if(iter != window.end() && *iter <= static_cast<long> (nums[i]) + static_cast<long> (t))
            {
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};

int main()
{
    vector<int> input = {-1, 2147483647};
    int k = 1;
    int t = 2147483647;
    Solution sol;
    bool result = sol.containsNearbyAlmostDuplicate(input, k, t); 
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
