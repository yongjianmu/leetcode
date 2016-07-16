#include "../include/header.h"

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    vector<string> mRet;

    void solve(string cur, int n, int left, int right)
    {
        //cout << left << ", " << right << endl;
        if(n == left && n == right)
        {
            mRet.push_back(cur);
            return;
        }

        if(n > left)
        {
            cur.push_back('(');
            solve(cur, n, left + 1, right);
            cur.pop_back();
        }

        if(right < left)
        {
            cur.push_back(')');
            solve(cur, n, left, right + 1);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        if(0 == n)
        {
            return mRet;
        }
        string orig = "";
        solve(orig, n, 0, 0);
        return mRet;
    }
};

int main() {
    int n = 3;
    Solution sol;
    vector<string> result = sol.generateParenthesis(n);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << endl;
    }

    return 0;
}