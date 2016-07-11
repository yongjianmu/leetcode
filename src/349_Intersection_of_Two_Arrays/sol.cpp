#include "../include/header.h"


/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
*/


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, bool> mp1;
        unordered_map<int, bool> mp2;
        for(int i = 0; i < nums1.size(); ++i)
        {
            mp1[nums1[i]] = true;
        }

        for(int i = 0; i < nums2.size(); ++i)
        {
            if(mp2.find(nums2[i]) == mp2.end() && mp1.find(nums2[i]) != mp1.end())
            {
                ret.push_back(nums2[i]);
                mp2[nums2[i]] = true;
            }
        }

        return ret;
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    Solution sol;
    vector<int> result = sol.intersection(nums1, nums2);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ", ";
    }
    cout << endl;

    return 0;
}
