#include "../include/header.h"

class Solution {
public:
    bool solve(vector<int>& nums, int k, int t, int p1, int p2)
    {
        cout << p1 << ", " << p2 << endl;

        if(p2 != p1 && p2 - p1 <= k && abs(static_cast<long long> (nums[p2] - nums[p1])) <= t)
        {
            cout << p1 << ",, " << p2 << endl;
            return true;
        }

        if(p1 < p2 && p2 < nums.size() - 1)
        {
            if(p1 < p2 - 1 && solve(nums, k, t, p1 + 1, p2))
            {
                return true;
            }

            if(solve(nums, k, t, p1, p2 + 1))
            {
                return true;
            }

            if(solve(nums, k, t, p1 + 1, p2 + 1))
            {
                return true;
            }
        }

        return false;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int size = nums.size();
        if(1 >= size)
        {
            return false;
        }

        return solve(nums, k, t, 0, 1);
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
