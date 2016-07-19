#include "../include/header.h"

/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

•All numbers (including target) will be positive integers.
•The solution set must not contain duplicate combinations.


For example, given candidate set [2, 3, 6, 7] and target 7,
 A solution set is:

[
  [7],
  [2, 2, 3]
]
 */

class Solution {
public:
    vector<vector<int> > mRet;

    void solve(int sum, int cur, vector<int>& res, int target, int size, vector<int>& candidiates)
    {
        if(sum == target)
        {
            mRet.push_back(res);
        }

        for(int i = cur; i < size; ++i)
        {
            if(sum + candidiates[i] <= target)
            {
                res.push_back(candidiates[i]);
                solve(sum + candidiates[i], i, res, target, size, candidiates);
                res.pop_back();
            }
        }
    }

    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        int size = candidates.size();
        if(0 == size)
        {
            return mRet;
        }
        vector<int> res;
        sort(candidates.begin(), candidates.end());
        solve(0, 0, res, target, size, candidates);
        return mRet;
    }
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}