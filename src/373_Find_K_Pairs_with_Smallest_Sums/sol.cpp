#include "../include/header.h"

/*
Example 1:

Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]



Example 2:

Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]



Example 3:

Given nums1 = [1,2], nums2 = [3],  k = 3

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]
*/

class Solution {
public:
    vector<pair<int, int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int> > ret;
        int size1 = nums1.size(), size2 = nums2.size();
        if (0 == size1 || 0 == size2)
        {
            return ret;
        }

        vector<int> pos(size1, -1);
        while (true)
        {
            if (k == ret.size())
            {
                break;
            }

            bool quit_flag = true;
            for (int i = 0; i < size1; ++i)
            {
                if (pos[i] < size2 - 1)
                {
                    quit_flag = false;
                    break;
                }
            }

            if (quit_flag)
            {
                break;
            }

            int p = 0;
            int cur_min = INT_MAX;
            for (int i = 0; i < size1; ++i)
            {
                if (pos[i] >= size2 - 1)
                {
                    continue;
                }
                int cur = nums2[pos[i] + 1] + nums1[i];
                if (cur_min > cur)
                {
                    cur_min = cur;
                    p = i;
                }
            }
            pair<int, int> pr;
            pr = make_pair(nums1[p], nums2[pos[p] + 1]);
            ++pos[p];
            ret.push_back(pr);
        }

        return ret;
    }
};

int main()
{
    vector<int> nums1 = {1, 1, 2};
    vector<int> nums2 = {1, 2, 3};
    int k = 10;
    Solution sol;
    vector<pair<int, int> > result = sol.kSmallestPairs(nums1, nums2, k);
    cout << "#### Result ####" << endl;
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i].first << ", " << result[i].second << endl;
    }

    return 0;
}