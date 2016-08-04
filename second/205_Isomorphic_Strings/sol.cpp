#include "../include/header.h"

/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len_s = s.length(), len_t = t.length();
        if(len_s != len_t)
        {
            return false;
        }

        unordered_map<char, char> ump1, ump2;
        for(int i = 0; i < len_s; ++i)
        {
            if(ump1.find(s[i]) == ump1.end())
            {
                if(ump2.find(t[i]) == ump2.end())
                {
                    ump1[s[i]] = t[i];
                    ump2[t[i]] = s[i];
                    s[i] = t[i];
                }
                else
                {
                    return false;
                }
            }
            else
            {
                s[i] = ump1[s[i]];
            }
        }
        return s == t;
    }
};
