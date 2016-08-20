#include "../include/header.h"

/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

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
    void insert(vector<pair<int, int> >& vec, pair<int, int> value)
    {
        int size = vec.size();
        if(0 == size)
        {
            vec.push_back(value);
        }

        int start = 0, end = size - 1;
        while(start <= end)
        {
            int mid = start + ((end - start) >> 1);
            int mid_sum = vec[mid].first + vec[mid].second;
            int value_sum = value.first + value.second;
            if(mid_sum == value_sum)
            {
                auto iter = vec.begin() + mid;
                vec.insert(iter, value);
                break;
            }
            else if(mid_sum < value_sum)
            {
                if(mid == size - 1)
                {
                    vec.push_back(value);
                    break;
                }
                else if((vec[mid + 1].first + vec[mid + 1].second) > value_sum)
                {
                    auto iter = vec.begin() + mid + 1;
                    vec.insert(iter, value);
                    break;
                }
                start = mid + 1;
            }
            else
            {
                if(mid == 0)
                {
                    vec.insert(vec.begin(), value);
                    break;
                }
                else if((vec[mid - 1].first + vec[mid - 1].second) < value_sum)
                {
                    auto iter = vec.begin() + mid;
                    vec.insert(iter, value);
                    break;
                }
                end = mid - 1;
            }
        }
    }

    vector<pair<int, int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int> >ret;
        int size1 = nums1.size(), size2 = nums2.size();
        if(0 == k || 0 == size1 || 0 == size2)
        {
            return ret;
        }

        for(int i = 0; i < size1; ++i)
        {
            for(int j = 0; j < size2; ++j)
            {
                insert(ret, make_pair(nums1[i], nums2[j]));
            }
        }

        if(k >= ret.size())
        {
            return ret;
        }

        vector<pair<int, int> > new_ret;
        new_ret.insert(new_ret.begin(), ret.begin(), ret.begin() + k);
        return new_ret;
    }
};

int main()
{
    vector<int> input1 = {-10,-4,0,0,6,6,6,7,10,22,100};
    vector<int> input2 = {3,5,6,7,8,100};
    int k = 100;
    Solution sol;
    vector<pair<int, int> > result = sol.kSmallestPairs(input1, input2, k);
    printResult();
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i].first << ", " << result[i].second << endl;
    }
    return 0;
}
