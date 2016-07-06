#include "../include/header.h"


/*
For example,
    Given "egg", "add", return true.

    Given "foo", "bar", return false.

    Given "paper", "title", return true.
*/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.length();
        if(0 == len)
        {
            return true;
        }

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for(int i = 0; i < len; ++i)
        {
            if(s[i] != t[i])
            {
                if(mp1.find(s[i]) == mp1.end())
                {
                    if(mp2.find(t[i]) == mp2.end())
                    {
                        mp1[s[i]] = t[i];
                        mp2[t[i]] = s[i];
                        s[i] = t[i];
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    s[i] = mp1[s[i]];
                }
            }
            else
            {
                if(mp1.find(s[i]) != mp1.end() &&  mp1[s[i]] != t[i])
                {
                    return false;
                }
                mp1[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }
        }

        return s == t;
    }
};

int main()
{
    string s = "aba";
    string t = "baa";

    Solution sol;
    bool result = sol.isIsomorphic(s, t);
    cout << result << endl;

    return 0;
}
