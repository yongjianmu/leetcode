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
        string ret = "";
        int len_s = s.length();
        int len_t = t.length();
        if(0 == len_s * len_t)
        {
            return ret;
        }

        int dict_int[129] = {0};
        int cnt_int[129] = {0};
        set<char> dict_c, cnt_c;
        for(int i = 0; i < len_t; ++i)
        {
            ++dict_int[t[i]];
            ++cnt_int[t[i]];
            dict_c.insert(t[i]);
        }

        int start = 0, len_ret = len_s + 1;
        while(start < len_s)
        {
            if(0 < dict_int[s[start]])
            {
                break;
            }
            ++start;
        }

        for(int i = start; i < len_s; ++i)
        {
            if(0 < dict_int[s[i]])
            {
                --cnt_int[s[i]];
                cnt_c.insert(s[i]);
            }

            if(cnt_c.size() == dict_c.size())
            {
                bool match_all = true;
                for(auto iter = dict_c.begin(); iter != dict_c.end(); ++iter)
                {
                    //cout << *iter << ", " << cnt_int[*iter] << endl;
                    if(cnt_int[*iter] > 0)
                    {
                        match_all = false;
                        break;
                    }
                }

                if(match_all)
                {
                    int len_cur = i - start + 1;
                    if(len_ret > len_cur)
                    {
                        len_ret = len_cur;
                        ret = s.substr(start, len_ret);
                    }

                    /* Update start */
                    ++cnt_int[s[start]];
                    if(dict_int[s[start]] == cnt_int[s[start]])
                    {
                        cnt_c.erase(s[start]);
                    }

                    ++start;
                    while(start < i)
                    {
                        if(0 < dict_int[s[start]])
                        {
                            break;
                        }
                        ++start;
                    }
                }
            }
        }
        return ret;
    }
};

int main()
{
    //string s = "A", t = "A";
    //string s = "ADOBECODEBANC", t = "ABC";
    string s = "bba", t = "ab";
    Solution sol;
    string result = sol.minWindow(s, t);
    cout << "#### Result ####" << endl;
    cout << result << endl;
    return 0;
}
