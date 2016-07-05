#include "../include/header.h"


/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int len_s = s.length();
        int len_t = t.length();
        if(len_s != len_t)
        {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

int main()
{
    //string s = "anagram";
    //string t = "nagaram";
    string s = "rat";
    string t = "car";
    Solution sol;
    bool result = sol.isAnagram(s, t);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
