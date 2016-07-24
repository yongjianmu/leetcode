#include "../include/header.h"

/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(0 == size)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int cnt = 1, last = nums[0], ret = 0;
        for(auto iter = nums.begin() + 1; iter != nums.end(); )
        {
            if(last == *iter)
            {
                ++cnt;
                if(2 < cnt)
                {
                    ++ret;
                    nums.erase(iter);
                }
                else
                {
                    ++iter;
                }
            }
            else
            {
                cnt = 1;
                last = *iter++;
            }
        }
        return size - ret;
    }
};

int main()
{
    vector<int> input = {1,1,1,2,2,3};
    Solution sol;
    int result = sol.removeDuplicates(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
