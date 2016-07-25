#include "../include/header.h"

/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

class Solution {
public:

    int numDecodings(string s) {
        int len = s.length();
        if(0 == len)
        {
            return len;
        }

        vector<int> dp(len, 0);
        if('1' > s[0] || '9' < s[0])
        {
            return 0;
        }
        dp[0] = 1;
        
        for(int i = 1; i < len; ++i)
        {
            if('0' == s[i])
            {
                if('1' == s[i - 1] || '2' == s[i - 1])
                {
                    dp[i] = dp[i - 1];
                }
                else
                {
                    return 0;
                }
            }
            else if('1' <= s[i] && '6' >= s[i])
            {
                if('0' > s[i - 1])
                {
                    return 0;
                }
                else if('1' == s[i - 1] || '2' == s[i - 1])
                {
                    if(i < len - 1 && '0' == s[i + 1])
                    {
                        dp[i] = dp[i - 1];
                        continue;
                    }

                    if(0 <= i - 2)
                    {
                        dp[i] = dp[i - 1] + dp[i - 2];
                    }
                    else
                    {
                        dp[i] = dp[i - 1] + 1;
                    }
                }
                else if('9' >= s[i - 1])
                {
                    dp[i] = dp[i - 1];
                }
                else
                {
                    return 0;
                }
            }
            else if('9' >= s[i])
            {
                if('0' > s[i - 1] || '9' < s[i - 1])
                {
                    return 0;
                }
                else if('1' == s[i - 1])
                {
                    if(i < len - 1 && '0' == s[i + 1])
                    {
                        dp[i] = dp[i - 1];
                        continue;
                    }

                    if(0 <= i - 2)
                    {
                        dp[i] = dp[i - 1] + dp[i - 2];
                    }
                    else
                    {
                        dp[i] = dp[i - 1] + 1;
                    }
                }
                else
                {
                    dp[i] = dp[i - 1];
                }
            }
            else
            {
                return 0;
            }
        }
        return dp[len - 1];
    }
};

int main()
{
    string input = "9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253";
    //string input = "110";
    Solution sol;
    int result = sol.numDecodings(input);
    printResult();
    cout << result << endl;

    return 0;
}
