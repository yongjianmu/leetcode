#include "../include/header.h"

/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int size = s.length();
        vector<bool> dp(size + 1, false);
        dp[0] = true;

        for(int i = 0; i < size; ++i)
        {
            for(int j = 0; j <= i; ++j)
            {
                string sub = s.substr(j, i - j + 1);
                if(find(wordDict.begin(), wordDict.end(), sub) != wordDict.end() && dp[j])
                {
                    dp[i + 1] = true;
                }
            }
        }
        return dp[size];
    }
};
