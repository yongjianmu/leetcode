#include "../include/header.h"

/*
Given "aacecaaa", return "aaacecaaa".
Given "abcd", return "dcbabcd".
*/

class Solution {
public:
    bool isPalindrome(string s)
    {
        int len = s.length();
        if(0 == len || 1 == len)
        {
            return true;
        }

        int left = 0;
        int right = len - 1;

        while(left <= len)
        {
            if(s[left++] != s[right--])
            {
                return false;
            }
        }

        return true;
    }

    string shortestPalindrome(string s) {
        int len = s.length();

        if(0 == len || 1 == len)
        {
            return s;
        }

        int pos = len;
        string add = "";
        //cout << "Input len: " << pos << endl;
        while(pos > 0)
        {
            //cout << "Current len: " << pos << endl;
            string sub = s.substr(0, pos);
            //cout << "Test str: " << sub << endl;
            if(isPalindrome(sub))
            {
                //cout << "Find: " << sub << endl; 
                if(pos < len)
                {
                    add += s.substr(pos, len - pos);
                    break;
                }
                else
                {
                    return s;
                }
            }
            --pos;
        }

        reverse(add.begin(), add.end());
        return add + s;
    }
};

int main()
{
    string input = "abcd";
    Solution sol;
    string result = sol.shortestPalindrome(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
