#include "../include/header.h"


/*
Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ret = 0;
        int size = tokens.size();
        stack<int> st;
        for(int i = 0; i < size; ++i)
        {
            if("+" != tokens[i] && "-" != tokens[i] && "*" != tokens[i] && "/" != tokens[i])
            {
                st.push(stoi(tokens[i]));
            }
            else
            {
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                switch(tokens[i][0])
                {
                    case '+':
                        st.push(x + y);
                        break;
                    case '-':
                        st.push(x - y);
                        break;
                    case '*':
                        st.push(x * y);
                        break;
                    case '/':
                        if(0 == y)
                        {
                            st.push(0);
                        }
                        else
                        {
                            st.push(x / y);
                        }
                        break;
                    default:
                        break;
                }
            }
        }

        if(!st.empty())
        {
            ret = st.top();
            st.pop();
        }

        return ret;
    }
};
