// 5_Longest_Palindromic_Substring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../include/header.h"

// Enum the center point of a palindrome string

class Solution {
public:
    void check(string s, int start, int end, int len, int& max_len, string& ret)
    {
        while (s[start] == s[end])
        {
            if (max_len < end - start + 1)
            {
                max_len = end - start + 1;
                ret = s.substr(start, max_len);
            }
            
            if (0 == start || len - 1 == end)
            {
                return;
            }

            --start;
            ++end;
        }
    }

    string longestPalindrome(string s) {
        int len = s.length();
        if (1 >= len)
        {
            return s;
        }

        if (2 == len)
        {
            if (s[0] == s[1])
            {
                return s;
            }
        }

        int max_len = 1;
        string ret = s.substr();
        for (int i = 1; i < len; ++i)
        {
            // check odd
            check(s, i, i, len, max_len, ret);

            // check even
            check(s, i - 1, i, len, max_len, ret);
        }

        return ret;
    }
};

int main()
{
    string s = "aba";
    Solution sol;
    string result = sol.longestPalindrome(s);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}

