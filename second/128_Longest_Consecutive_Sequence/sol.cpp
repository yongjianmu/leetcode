#include "../include/header.h"

/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ret = 0;
        int size = nums.size();
        if(0 == size)
        {
            return ret;
        }

        unordered_map<int, int> ump;
        for(int i = 0; i < size; ++i)
        {
            ++ump[nums[i]];
        }

        for(int i = 0; i < size; ++i)
        {
            int cnt = 1;
            if(ump.count(nums[i]) > 0)
            {
                int left = nums[i] - 1, right = nums[i] + 1;
                while(ump.count(left) > 0)
                {
                    ump.erase(left);
                    --left;
                    ++cnt;
                }
                while(ump.count(right) > 0)
                {
                    ump.erase(right);
                    ++right;
                    ++cnt;
                }
            }
            ret = max(ret, cnt);
        }

        return ret;
    }
};

int main()
{
    vector<int> input = {100, 4, 200, 1, 3, 2};
    Solution sol;
    int result = sol.longestConsecutive(input);
    printResult();
    cout << result << endl;

    return 0;
}
