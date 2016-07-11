#include "../include/header.h"


/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        int pos1 = 0, pos2 = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        while(pos1 < nums1.size() && pos2 < nums2.size())
        {
            if(nums1[pos1] > nums2[pos2])
            {
                ++pos2;
            }
            else if(nums1[pos1] < nums2[pos2])
            {
                ++pos1;
            }
            else
            {
                ret.push_back(nums1[pos1]);
                ++pos1;
                ++pos2;
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
    vector<int> ret = sol.intersect(nums1, nums2);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < ret.size(); ++i)
    {
        cout << ret[i] << endl;
    }
    cout << endl;

    return 0;
}
