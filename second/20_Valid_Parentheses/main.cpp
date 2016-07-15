#include "../include/header.h"

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        if(1 == len % 2)
        {
            return false;
        }

        stack<char> st;
        for(int i = 0; i < len; ++i)
        {
            switch(s[i])
            {
                case '(':
                    st.push(s[i]);
                    break;
                case ')':
                    if(!st.empty() && '(' == st.top())
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case '[':
                    st.push(s[i]);
                    break;
                case ']':
                    if(!st.empty() && '[' == st.top())
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case '{':
                    st.push(s[i]);
                    break;
                case '}':
                    if(!st.empty() && '{' == st.top())
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                default:
                    break;
            }
        }

        return st.empty();
    }
};

int main() {
    string input = "()[]{}";
    Solution sol;
    bool result = sol.isValid(input);
    cout << "### Result ####" << endl;
    cout << result << endl;

    return 0;
}