#include "../include/header.h"

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        vector<double> medians;
        for (int i=k; ; ++i) 
        {
            // Push the current median.
            medians.push_back((double(*mid) + *next(mid, k%2 - 1)) / 2);

            // If all done, return.
            if (i == nums.size()) break;
                
            // Insert nums[i].
            window.insert(nums[i]);
            if (nums[i] < *mid)
                mid--;

            // Erase nums[i-k].
            if (nums[i-k] <= *mid)
                mid++;
            window.erase(window.lower_bound(nums[i-k]));
        }
        return medians;
    }
};

int main()
{
    vector<int> input = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution sol;
    vector<double> ret = sol.medianSlidingWindow(input, k);
    printResult();
    for(auto iter = ret.begin(); iter != ret.end(); ++iter)
    {
        cout << *iter << endl;
    }
    return 0;
}
