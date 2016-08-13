#include "../include/header.h"

/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int len = s.length();
        if(1 >= len)
        {
            return s;
        }

        vector<int> dict(26, 0);
        vector<bool> vis(26, false);
        stack<char> st;

        for(int i = 0; i < len; ++i)
        {
            ++dict[s[i] - 'a'];
        }

        for(int i = 0; i < len; ++i)
        {
            int index = s[i] - 'a';
            --dict[index];

            if(vis[index])
            {
                continue;
            }

            while(!st.empty() && dict[st.top() - 'a'] > 0 && st.top() > s[i])
            {
                char c = st.top();
                st.pop();
                vis[c - 'a'] = false;
            }

            st.push(s[i]);
            vis[s[i] - 'a'] = true;
        }

        string ret = "";
        while(!st.empty())
        {
            ret.insert(ret.begin(), st.top());
            st.pop();
        }
        return ret;
    }
};

int main()
{
    //string input = "cbacdcbc";
    string input = "bcabc";
    Solution sol;
    string result = sol.removeDuplicateLetters(input);
    printResult();
    cout << result << endl;

    return 0;
}
