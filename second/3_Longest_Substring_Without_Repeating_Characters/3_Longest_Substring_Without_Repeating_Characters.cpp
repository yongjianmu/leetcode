// 3_Longest_Substring_Without_Repeating_Characters.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../include/header.h"

/*
Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        vector<char> vec;

        for (int i = 0; i < s.length(); ++i)
        {
            auto iter = find(vec.begin(), vec.end(), s[i]);
            if (iter == vec.end())
            {
                vec.push_back(s[i]);
                ret = max(ret, static_cast<int> (vec.size()));
                cout << ret << endl;
            }
            else
            {
                vec.erase(vec.begin(), iter + 1);
                vec.push_back(s[i]);
                cout << "size: " << vec.size() << endl;
            }
        }
        return ret;
    }
};
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count[128];
        memset(count, -1, 128 * sizeof(int));
        int len = 0, maxL = 0;
        for (int i = 0; i< s.size(); i++, len++)
        {
            if (count[static_cast<int> (s[i])] >= 0)
            {
                maxL = max(len, maxL);
                len = 0;
                i = count[static_cast<int> (s[i])] + 1;
                memset(count, -1, 128 * sizeof(int));
            }
            count[static_cast<int> (s[i])] = i;
        }
        return max(len, maxL);
    }
};

int main()
{
    string s = "abcabcbb";
    Solution sol;
    int result = sol.lengthOfLongestSubstring(s);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}

