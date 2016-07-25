#include "../include/header.h"

/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

/*
Solution: dp

  g r e a t
r 0 1 0 0 0
g 1 0 0 0 0
t 0 0 0 0 1
a 0 0 0 1 0
e 0 0 1 0 0


*/

class Solution {
public:

    bool isScramble(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 != len2)
        {
            return false;
        }

        if(1 == len1)
        {
            return s1 == s2;
        }

        vector<vector<int> > dp(len1, vector<int>(len1, 0));
        for(int i = 0; i < len1; ++i)
        {
            for(int j = 0; j < len2; ++j)
            {
                if(s1[i] == s2[j])
                {
                    dp[i][j] = 1;
                }
            }
        }


    }
};

int main()
{
    string s1 = "abcd";
    string s2 = "bdac";

    Solution sol;
    bool result = sol.isScramble(s1, s2);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
