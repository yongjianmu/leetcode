#include "../include/header.h"

/*
A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

Examples:
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
Follow up:
Can you do it in O(n) time?
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        if(0 == size)
        {
            return 0;
        }

        int ret = 1;
        int start = 1;
        bool found = false;
        for(; start < size; ++start)
        {
            if(nums[start] != nums[start - 1])
            {
                found = true;
                break;
            }
        }
        if(!found)
        {
            return ret;
        }

        bool increase = nums[start] - nums[start - 1] > 0 ? true : false;
        for(int i = start; i < size; ++i)
        {
            if(nums[i] > nums[i - 1])
            {
                if(increase)
                {
                    ++ret;
                    increase = !increase;
                }
            }
            else if(nums[i] < nums[i - 1])
            {
                if(!increase)
                {
                    ++ret;
                    increase = !increase;
                }
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> input = {3, 3, 3, 2, 5};
    Solution sol;
    int result = sol.wiggleMaxLength(input);
    printResult();
    cout << result << endl;

    return 0;
}
