#include "../include/header.h"

/*
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s = s.length(), len_p = p.length();
        int cnt = count(p.begin(), p.end(), '*');
        if(len_p - cnt > len_s)
        {
            return false;
        }

        vector<bool> dp(len_p + 1, false);
        dp[0] = true;
        for(int j = 1; j <= len_p; ++j)
        {
            if('*' == p[j - 1])
            {
                dp[j] = dp[j - 1];
            }
        }
        for(int i = 1; i <= len_s; ++i)
        {
            vector<bool> cur(len_p + 1, false);
            for(int j = 1; j <= len_p; ++j)
            {
                if('*' == p[j - 1])
                {
                    cur[j] = dp[j] || cur[j - 1];
                }
                else
                {
                    if(s[i - 1] == p[j - 1] || '?' == p[j - 1])
                    {
                        cur[j] = dp[j - 1];
                    }
                }
            }
            dp = cur;
        }
        return dp[len_p];
    }
};

int main() {
    string s = "aaab";
    string p = "a*b";
    Solution sol;
    bool result = sol.isMatch(s, p);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}