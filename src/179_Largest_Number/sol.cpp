#include "../include/header.h"

/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/


bool comp(int a, int b)
{
    string sa, sb;
    stringstream aa, bb;
    aa << a;
    bb << b;
    aa >> sa;
    bb >> sb;
    return sa + sb > sb + sa;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ret = "";
        int size = nums.size();
        if(0 == size)
        {
            return 0;
        }
        sort(nums.begin(), nums.end(), comp);

        bool flag = false;
        for(int i = 0; i < size; ++i)
        {
            if((0 == i || flag) && 0 == nums[i] && i != size - 1)
            {
                flag = true;
                continue;
            }
            flag = false;
            string curr;
            stringstream ss;
            ss << nums[i];
            ss >> curr;
            ret += curr;
        }
        return ret;
    }
};

int main()
{
    vector<int> input = {3, 30, 34, 5, 9};
    Solution sol;
    string result = sol.largestNumber(input);
    cout << result << endl;
    return 0;
}
