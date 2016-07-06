#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int ret = 0;
        int len = s.length();
        bool* match = new bool[len];
        stack<int> st;

        for(int i = 0; i < len; ++i)
        {
            match[i] = false;
            if('(' == s[i])
            {
                st.push(i);
            }
            else if(!st.empty() && ')' == s[i])
            {
                match[st.top()] = match[i] = true;
                st.pop();
            }
        }

        int tmp = 0;
        for(int i = 0; i < len; ++i)
        {
            if(!match[i])
            {
                tmp = 0;
            }
            else
            {
                ++tmp;
                ret = max(ret, tmp);
            }
        }

        delete[] match;
        return ret;
    }
};

int main()
{
    string input = ")()(((())))(";
    Solution sol;
    cout << sol.longestValidParentheses(input) << endl;
    return 0;
}
