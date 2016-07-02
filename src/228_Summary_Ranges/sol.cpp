#include "../include/header.h"

/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

class Solution {
public:
    void pushString(vector<int>& nums, vector<string>& ret, int start, int end, bool last)
    {
        cout << start << ", " << end << endl;
        int cnt;
        if(last)
        {
            cnt = end - start;
        }
        else
        {
            cnt = end - start - 1;
        }
        if(0 == cnt)
        {
            string cur;
            stringstream ss;
            ss << nums[start];
            ss >> cur;
            ret.push_back(cur);
        }
        else
        {
            string cur;
            stringstream ss;
            ss << nums[start];
            ss << '-';
            ss << '>';
            if(last)
            {
                ss << nums[end];
            }
            else
            {
                ss << nums[end - 1];
            }
            ss >> cur;
            ret.push_back(cur);
        }
    }

    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int size = nums.size();
        if(0 == size)
        {
            return ret;
        }

        int start = 0;
        int end = 0;
        while(end < size)
        {
            if(end - start == nums[end] - nums[start])
            {
                ++end;
                continue;
            }

            pushString(nums, ret, start, end, false);
            start = end;
        }
        pushString(nums, ret, start, end - 1, true);
        return ret;
    }
};

int main()
{
    vector<int> input = {0,1,2,4,5,7};
    Solution sol;
    vector<string> result = sol.summaryRanges(input);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ", ";
    }
    cout << endl;

    return 0;
}
