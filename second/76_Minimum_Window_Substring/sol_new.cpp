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
    string minWindow(string S, string T) {
        int len_s = S.length(), len_t = T.length();
        string ret = "";
        if(0 == len_t || len_s < len_t) return ret;

        int ret_len = INT_MAX;
        unordered_map<char, int> dict, cnt;
        for(char c : T)
        {
            ++dict[c];
            ++cnt[c];
        }

        int start = 0, L = -1;
        for(int i = 0; i < len_s; ++i)
        {
            if(dict.find(S[i]) != dict.end())
            {
                if(--cnt[S[i]] >= 0)
                {
                    --len_t;
                }
            }

            if(len_t > 0) continue;

            while(start <= i)
            {
                if(dict.find(S[start]) != dict.end())
                {
                    if(cnt[S[start]] < 0)
                    {
                        ++cnt[S[start]];
                    }
                    else
                    {
                        break;
                    }
                }
                ++start;
            }

            // got potential answer
            if(ret_len > i - start + 1)
            {
                ret_len = i - start + 1;
                L = start;
            }
        }

        return L == -1 ? "" : string(S, L, ret_len);
    }
};
