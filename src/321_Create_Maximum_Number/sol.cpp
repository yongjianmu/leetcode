#include "../include/header.h"


/*
Example 1:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
return [9, 8, 6, 5, 3]

Example 2:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
return [6, 7, 6, 0, 4]

Example 3:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
return [9, 8, 9]
*/


bool cmp(int a, int b)
{
    return a > b;
}

class Solution {
public:

    vector<int> calDp(vector<int>& nums, unordered_map<int, int> mp, int n) // Calculate nth dp
    {
        vector<int> ret;
        unordered_map<int, bool> m;

        for(int i = 0; i < nums.size(); ++i)
        {
            m[nums[i]] = false; // Not use
        }

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < nums.size(); ++j)
            {
                if((!m[nums[j]]) && (static_cast<int> (nums.size()) - mp[nums[j]] - (n - i) >= 0))
                {
                    if(i > 0 && mp[nums[j]] <= mp[ret[i - 1]])
                    {
                        continue;
                    }
                    ret.push_back(nums[j]);
                    m[nums[j]] = true;
                    break;
                }
            }
        }

        return ret;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ret;
        unordered_map<int, int> mp1, mp2;

        for(int i = 0; i < nums1.size(); ++i)
        {
            mp1[nums1[i]] = i;
        }

        for(int i = 0; i < nums2.size(); ++i)
        {
            mp2[nums2[i]] = i;
        }

        sort(nums1.begin(), nums1.end(), cmp);
        sort(nums2.begin(), nums2.end(), cmp);

        vector<vector<int> > dp1, dp2;
        cout << "dp1" << endl;
        for(int i = 0; i < min(k, static_cast<int> (nums1.size())); ++i) // Calculate DP
        {
            dp1.push_back(calDp(nums1, mp1, i + 1));
            for(int j = 0; j < dp1[i].size(); ++j)
            {
                cout << dp1[i][j] << ", ";
            }
            cout << endl;
        }

        cout << "dp2" << endl;
        for(int i = 0; i < min(k, static_cast<int> (nums2.size())); ++i) // Calculate DP
        {
            dp2.push_back(calDp(nums2, mp2, i + 1));
            for(int j = 0; j < dp2[i].size(); ++j)
            {
                cout << dp2[i][j] << ", ";
            }
            cout << endl;
        }

        // Enum
        int value = INT_MIN;
        for(int i = 1; i <= k; ++i)
        {
            int len1 = i - 1, len2 = k - i - 1;

            if(len1 > dp1[len1].size() - 1 || len2 > dp2[len2].size() - 1)
            {
                continue;
            }

            int value_cur = 0;
            vector<int> arr_cur;
            vector<int> cur1 = dp1[len1];
            vector<int> cur2 = dp2[len2];

            int start1 = 0, start2 = 0;
            while(start1 + start2 <= k - 2)
            {
                if(dp1[len1][start1] >= dp2[len2][start2])
                {
                    if(start1 < len1 - 1)
                    {
                        arr_cur.push_back(dp1[len1][start1]);
                        ++start1;
                    }
                    else
                    {
                        arr_cur.push_back(dp2[len2][start2]);
                        ++start2;
                    }
                }
                else
                {
                    if(start2 < len2 - 1)
                    {
                        arr_cur.push_back(dp2[len2][start2]);
                        ++start2;
                    }
                    else
                    {
                        arr_cur.push_back(dp2[len2][start2]);
                        ++start1;
                    }
                }
            }
            
            for(int j = 0; j < k; ++j)
            {
                value_cur = value_cur * 10 + arr_cur[j];
            }

            value = max(value, value_cur);
            cout << value << endl;
        }

        if(0 == value)
        {
            ret.push_back(0);
        }
        else
        {
            while(0 != value)
            {
                int x = value % 10;
                ret.push_back(x);
                value /= 10;
            }
        }

        return ret;
    }
};

int main()
{
    vector<int> nums1 = {3, 4, 6, 5};
    vector<int> nums2 = {9, 1, 2, 5, 8, 3};
    int k = 5;
    Solution sol;
    vector<int> result = sol.maxNumber(nums1, nums2, k);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ", ";
    }
    cout << endl;

    return 0;
}
