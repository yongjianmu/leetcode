#include "../include/header.h"


/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/

class Solution {
public:
    int mRet;

    bool check(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }

    void solve(int start, int end, vector<string>& cur, string s, int cur_cut)
    {
        if(mRet <= cur_cut - 1)
        {
            return;
        }

        if(start >= end)
        {
            mRet = min(mRet, cur_cut - 1);
        }

        for(int i = start; i < end; ++i)
        {
            string tmp = s.substr(start, i - start + 1);
            if(check(tmp))
            {
                cur.push_back(tmp);
                solve(i + 1, end, cur, s, cur_cut + 1);
                cur.pop_back();
            }
        }
    }

    int minCut(string s) {
        int len = s.length();
        mRet = len == 0 ? 0 : len - 1;
        if(0 == len)
        {
            return mRet;
        }

        vector<string> cur;
        solve(0, len, cur, s, 0);
        return mRet;
    }
};

int main()
{
    string input = "aab";
    Solution sol;
    int result = sol.minCut(input);
    printResult();
    cout << result << endl;

    return 0;
}
