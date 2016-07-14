#include "../include/header.h"

/*
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        if(s == p)
        {
            return true;
        }

        int len_s = s.length(), len_p = p.length();
        if(0 == len_p)
        {
            return 0 == len_s;
        }

        if('*' == p[1])
        {
            while(0 != s.length() && (p[0] == s[0] || '.' == p[0]))
            {
                if(isMatch(s, p.substr(2, len_p- 2))) // * as zero
                {
                    return true;
                }
                s.erase(0, 1); // Use * if first letter is equal
            }
            return isMatch(s, p.substr(2, len_p - 2)); // Use *
        }
        else
        {
            if((p[0] == s[0] || '.' == p[0]) && 0 != len_s)
            {
                return isMatch(s.substr(1, len_s - 1), p.substr(1, len_p - 1));
            }
        }
        return false;
    }
};


int main() {
    string s = "a";
    string p = "ab*";
    Solution sol;
    bool result = sol.isMatch(s, p);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}