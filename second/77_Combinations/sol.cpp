#include "../include/header.h"

/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
    vector<vector<int> > mRet;

    void solve(int pos, int len, vector<int> cur, int n, int k)
    {
        if(len == k)
        {
            mRet.push_back(cur);
            return;
        }

        for(int i = pos; i <= n - k + len; ++i)
        {
            cur.push_back(i + 1);
            solve(i + 1, len + 1, cur, n, k);
            cur.pop_back();
        }
    }

    vector<vector<int> > combine(int n, int k) {
        if(0 == n || 0 == k || n < k)
        {
            return mRet;
        }
        
        vector<int> cur;
        solve(0, 0, cur, n, k);
        return mRet;
    }
};

int main()
{
    int n = 4, k = 2;
    Solution sol;
    vector<vector<int> > result = sol.combine(n, k);
    printVector2D(result, false);
    return 0;
}
