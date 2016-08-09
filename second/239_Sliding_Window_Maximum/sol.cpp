#include "../include/header.h"

/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].
*/

struct cmp
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const 
    {
        return a.second <= b.second;
    }
};

struct MatchFirst
{
   MatchFirst(const int& first, const int& second) : mFirst(first), mSecond(second) {}

   bool operator()(const pair<int, int>& val) {
        return val.first == mFirst && val.second == mSecond;
   }

   const int& mFirst;
   const int& mSecond;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        int size = nums.size();
        if(0 == size)
        {
            return ret;
        }

        set<pair<int, int>, cmp> s;
        vector<pair<int, int> > vec;
        int i = 0;
        for(; i <= k - 2; ++i)
        {
            pair<int, int> cur = make_pair(i, nums[i]);
            vec.push_back(cur);
            s.insert(vec[i]);
        }

        int start = 0;
        for(; i < size; ++i)
        {
            pair<int, int> cur = make_pair(i, nums[i]);
            vec.push_back(cur);
            s.insert(vec[i]);
            cout << start << "--" << i << endl;
            for(auto it = s.begin(); it != s.end(); ++it) {cout << it->second << ", ";}
            cout << endl;
            cout << vec[start].second << endl;
            auto iter = s.rbegin();
            ret.push_back(iter->second);
            auto iter_erase = find_if(s.begin(), s.end(), MatchFirst(vec[start].first, vec[start].second));
            s.erase(iter_erase);
            ++start;
        }
        return ret;
    }
};

int main()
{
    //vector<int> input = {1,3,-1,-3,5,3,6,7};
    vector<int> input = {-7,-8,7,5,7,1,6,0};
    int k = 4;
    Solution sol;
    vector<int> result = sol.maxSlidingWindow(input, k);
    printResult();
    printVector1D(result, false);

    return 0;
}
