#include <string>
#include <iostream>

using namespace std;

/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

class Solution {
public:
    bool solve(int pos1, int pos2, int pos3, string s1, string s2, string s3)
    {
        if(pos1 == s1.length() && pos2 == s2.length() && pos3 == s3.length())
        {
            return true;
        }

        if(pos1 < s1.length() && pos3 < s3.length() && s1[pos1] == s3[pos3])
        {
            if(true == solve(pos1 + 1, pos2, pos3 + 1, s1, s2, s3))
            {
                return true;
            }
        }

        if(pos2 < s2.length() && pos3 < s3.length() && s2[pos2] == s3[pos3])
        {
            if(true == solve(pos1, pos2 + 1, pos3 + 1, s1, s2, s3))
            {
                return true;
            }
        }

        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();

        if(len1 + len2 != len3)
        {
            return false;
        }

        return solve(0, 0, 0, s1, s2, s3);
    }
};

int main()
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    string s4 = "aadbbbaccc";
    string s6 = "a";
    string s7 = "d";
    string s8 = "ad";

    Solution sol;
    cout << sol.isInterleave(s1, s2, s4) << endl;

    return 0;
}
