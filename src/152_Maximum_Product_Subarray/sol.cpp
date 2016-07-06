#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;


/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
    the contiguous subarray [2,3] has the largest product = 6.
*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret = 0;
        int size = nums.size();
        if(0 == size)
        {
            return ret;
        }

        ret = nums[0];
        int min_product = ret, max_product = ret;

        for(int i = 1; i < size; ++i)
        {
            int t = max_product;
            max_product = max(t * nums[i], min_product * nums[i]);
            max_product = max(max_product, nums[i]);
            min_product = min(t * nums[i], min_product * nums[i]);
            min_product = min(min_product, nums[i]);
            ret = max(max_product, ret);
        }

        return ret;
    }
};


int main()
{
    vector<int> input = {2, -5, -2, -4, 3};
    Solution sol;
    cout << sol.maxProduct(input) << endl;

    return 0;
}
