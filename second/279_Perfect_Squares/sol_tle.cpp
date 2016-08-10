#include "../include/header.h"

/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

class Solution {
public:
    vector<int> mDict;
    int mRet;

    void solve(int n, int num)
    {
        if(mRet <= num)
        {
            return;
        }

        if(find(mDict.begin(), mDict.end(), n) != mDict.end())
        {
            mRet = min(mRet, num + 1);
            return;
        }

        for(auto iter = mDict.begin(); *iter <= n && iter != mDict.end(); ++iter)
        {
            solve(n - *iter, num + 1);
        }
    }

    int numSquares(int n) {
        for(int i = 1; i * i <= n; ++i)
        {
            mDict.push_back(i * i);
        }

        mRet = n;
        solve(n, 0);
        return mRet;
    }
};

int main()
{
    int n = 12;
    Solution sol;
    int result = sol.numSquares(n);
    printResult();
    cout << result << endl;

    return 0;
}
