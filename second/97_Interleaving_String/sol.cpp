#include "../include/header.h"

/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

Subscribe to see which companies asked this question
*/

class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if(len1 + len2 != len3)
        {
            return false;
        }

        vector<vector<bool> > dp(len1 + 1, vector<bool>(len2 + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= len1; ++i)
        {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }
        for(int j = 1; j <= len2; ++j)
        {
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        for(int i = 1; i <= len1; ++i)
        {
            for(int j = 1; j <= len2; ++j)
            {
                dp[i][j] = (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) || (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
            }
        }
        return dp[len1][len2];
    }
};

int main()
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    //string s3 = "aadbbcbcac";
    string s3 = "aadbbbaccc";
    Solution sol;
    bool result = sol.isInterleave(s1, s2, s3);
    printResult();
    cout << result << endl;

    return 0;
}
