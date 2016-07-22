#include "../include/header.h"

/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".
*/


class Solution {
public:
    string minWindow(string s, string t) {
    }
};

int main()
{
    string s = "A", t = "A";
    Solution sol;
    string result = sol.minWindow(s, t);
    cout << "#### Result ####" << endl;
    cout << result << endl;
    return 0;
}
