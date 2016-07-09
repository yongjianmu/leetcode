#include "../include/header.h"

/*
Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x1 = INT_MAX, x2 = INT_MAX;
        for(int num : nums)
        {
            if(num <= x1)
            {
                x1 = num;
            }
            else if(num <= x2)
            {
                x2 = num;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
