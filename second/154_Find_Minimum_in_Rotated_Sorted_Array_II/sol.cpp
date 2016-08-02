#include "../include/header.h"

/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/


class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if(1 == size)
        {
            return nums[0];
        }

        sort(nums.begin(), nums.end());
        return nums[0];
    }
};

int main()
{
    vector<int> input = {3, 3, 1, 3};
    Solution sol;
    int result = sol.findMin(input);
    printResult();
    cout << result << endl;

    return 0;
}
