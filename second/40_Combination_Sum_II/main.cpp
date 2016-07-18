#include "../include/header.h"

/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

•All numbers (including target) will be positive integers.
•The solution set must not contain duplicate combinations.


For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
 A solution set is:

[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
 */

class Solution {
public:
    vector<vector<int> > mRet;

    void solve(int sum, int cur, int target, vector<int>& res, int size, vector<int>& candidates)
    {
        if(sum == target)
        {
            mRet.push_back(res);
        }

        for(int i = cur; i < size; ++i)
        {
            if(sum + candidates[i] <= target)
            {
                if(i > cur && candidates[i] == candidates[i - 1])
                {
                    continue;
                }

                res.push_back(candidates[i]);
                solve(sum + candidates[i], i + 1, target, res, size, candidates);
                res.pop_back();
            }
            else
            {
                break;
            }
        }
    }

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        int size = candidates.size();
        if(0 == size)
        {
            return mRet;
        }
        vector<int> res;
        sort(candidates.begin(), candidates.end());
        solve(0, 0, target, res, size, candidates);
        return mRet;
    }
};

int main() {
    vector<int> input = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    Solution sol;
    vector<vector<int> > result = sol.combinationSum2(input, target);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        for(int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}