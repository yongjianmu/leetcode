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
        if(0 == len_p)
        {
            return 0 == len_s;
        }

        if('?' == p[0])
        {
            if(0 == len_s)
            {
                return false;
            }
            return isMatch(s.substr(1, len_s - 1), p.substr(1, len_p - 1));
        }
        else if('*' == p[0])
        {
            if(isMatch(s, p.substr(1, len_p - 1)))
            {
                return true;
            }

            if(0 >= len_s)
            {
                return false;
            }
            return isMatch(s.substr(1, len_s - 1), p);
        }
        else
        {
            if(0 < len_s && s[0] == p[0])
            {
                return isMatch(s.substr(1, len_s - 1), p.substr(1, len_p - 1));
            }
        }
        return false;
    }
};

int main() {
    string s = "";
    string p = "?";
    Solution sol;
    bool result = sol.isMatch(s, p);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}