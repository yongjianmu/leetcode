#include "../include/header.h"


/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
    Given [3,2,1,5,6,4] and k = 2, return 5.
*/

bool myCompare(int a, int b)
{
    return a >= b;
}

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), myCompare);
        return nums[k - 1];
    }
};

int main()
{
    vector<int> input = {3,2,3,1,2,4,5,5,6};
    Solution sol;
    int result = sol.findKthLargest(input, 4);
    cout << result << endl;
    return 0;
}
