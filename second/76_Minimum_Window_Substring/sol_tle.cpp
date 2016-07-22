#include "../include/header.h"

/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".
*/

class detect
{
private:
    unordered_map<char, int> mUmp;
    int mLen;
    int mStart;
    int mEnd;
public:
    detect(unordered_map<char, int> mp, int len, int start)
    {
        mUmp = mp;
        mLen = len;
        mStart = start;
        mEnd = -1;
    }

    ~detect() {}

    void attempt(char c, int pos)
    {
        if(mUmp.find(c) != mUmp.end() && mUmp[c] > 0)
        {
            --mUmp[c];
            --mLen;
            if(0 == mLen)
            {
                mEnd = pos;
            }
        }
    }

    bool isValid()
    {
        return 0 == mLen;
    }

    int getStart()
    {
        return mStart;
    }

    int getEnd()
    {
        return mEnd;
    }
};


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

        unordered_map<char, int> mp;
        for(int i = 0; i < len_t; ++i)
        {
            ++mp[t[i]];
        }

        vector<detect> de;
        for(int i = 0; i < len_s; ++i)
        {
            if(mp.find(s[i]) != mp.end())
            {
                if(len_s - i >= len_t)
                {
                    detect cur(mp, len_t, i);
                    de.push_back(cur);
                }
                for(int j = 0; j < de.size(); ++j)
                {
                    de[j].attempt(s[i], i);
                }
            }
        }


        int ret_len = INT_MAX;
        int ret_i = -1;
        for(int i = 0; i < de.size(); ++i)
        {
            if(!de[i].isValid())
            {
                continue;
            }

            int len_tmp = de[i].getEnd() - de[i].getStart() + 1;
            if(ret_len > len_tmp)
            {
                ret_len = len_tmp;
                ret_i = i;
            }
        }

        if(-1 == ret_i)
        {
            return ret;
        }

        ret = s.substr(de[ret_i].getStart(), ret_len);
        return ret;
    }
};

int main()
{
    string s = "A", t = "A";
    Solution sol;
    string result = sol.minWindow(s, t);
    cout << "#### Result ####" << endl;
    cout << result << endl;
    return 0;
}
