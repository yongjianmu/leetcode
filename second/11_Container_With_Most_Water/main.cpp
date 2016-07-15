#include "../include/header.h"

/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        if(1 >= size)
        {
            return 0;
        }

        int ret = 0;
        int start = 0, end = size - 1;

        while(start < end)
        {
            ret = max(ret, (end - start) * min(height[start], height[end]));
            if(height[start] <= height[end])
            {
                ++start;
            }
            else
            {
                --end;
            }
        }

        return ret;
    }
};

int main() {
    vector<int> input = {10,14,10,4,10,2,6,1,6,12};
    Solution sol;
    int result = sol.maxArea(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}