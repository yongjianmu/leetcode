#include "../include/header.h"

/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if(1 >= size)
        {
            return;
        }

        int i = size - 2, pos = -1;
        for(; i >= 0; --i)
        {
            if(nums[i] < nums[i + 1])
            {
                pos = i;
                break;
            }
        }

        if(-1 == pos)
        {
            /* Last permutation */
            reverse(nums.begin(), nums.end());
        }
        else
        {
            pos = i;
            int l = size - 1;
            for(i = size - 1; i > pos; --i)
            {
                if(nums[i] > nums[pos])
                {
                    l = i;
                    break;
                }
            }
            int tmp = nums[pos];
            nums[pos] = nums[l];
            nums[l] = tmp;
            auto iter = nums.begin();
            advance(iter, pos + 1);
            reverse(iter, nums.end());
        }
    }
};

int main() {
    cout << "#### Result ####" << endl;
    return 0;
}