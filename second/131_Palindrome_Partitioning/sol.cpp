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
    vector<vector<string> > mRet;

    bool check(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }

    void solve(int start, int end, vector<string>& cur, string s)
    {
        if(start >= end)
        {
            mRet.push_back(cur);
        }

        for(int i = start; i < end; ++i)
        {
            string tmp = s.substr(start, i - start + 1);
            if(check(tmp))
            {
                cur.push_back(tmp);
                solve(i + 1, end, cur, s);
                cur.pop_back();
            }
        }
    }

    vector<vector<string> > partition(string s) {
        int len = s.length();
        if(0 == len)
        {
            return mRet;
        }

        vector<string> cur;
        solve(0, len, cur, s);
        return mRet;
    }
};

int main()
{
    string input = "aab";
    Solution sol;
    vector<vector<string> > result = sol.partition(input);
    printResult();
    printVector2D(result, false);

    return 0;
}
