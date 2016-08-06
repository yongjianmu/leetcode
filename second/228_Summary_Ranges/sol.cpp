#include "../include/header.h"

/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int size = nums.size();
        if(0 == size)
        {
            return ret;
        }

        sort(nums.begin(), nums.end());
        int start = 0;
        for(int i = 0; i < size; ++i)
        {
            if(i < size - 1 && nums[i] != nums[i + 1] - 1)
            {
                string cur;
                stringstream ss;
                ss << nums[start];
                if(start != i)
                {
                    ss << "->";
                    ss << nums[i];
                }
                ss >> cur;
                ret.push_back(cur);
                start = i + 1;
            }
        }

        if(start == size - 1)
        {
            string cur;
            stringstream ss;
            ss << nums[start];
            ss >> cur;
            ret.push_back(cur);
        }
        else if(start < size - 1)
        {
            string cur;
            stringstream ss;
            ss << nums[start];
            ss << "->";
            ss << nums[size - 1];
            ss >> cur;
            ret.push_back(cur);
        }

        return ret;
    }
};


int main()
{
    vector<int> input = {0, 1, 2, 4, 5, 7};
    Solution sol;
    vector<string> result = sol.summaryRanges(input);
    printResult();
    printVector1D(result, true);

    return 0;
}
