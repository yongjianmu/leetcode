#include "../include/header.h"

/*
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
*/


class Solution {
public:
    stack<char> st;

    int getDigits(long long num)
    {
        if(0 == num)
        {
            return 1;
        }

        int ret = 0;
        while(0 != num)
        {
            num /= 10;
            ++ret;
        }
        return ret;
    }

    void handleParentheses(long long& ret)
    {
        long long cur = 0;
        bool flag = false;
        char last_op = '+';
        bool last_op_flag = true;
        while(!st.empty())
        {
            char op = st.top();
            st.pop();
            if('(' == op)
            {
                break;
            }

            if('0' <= op && '9' >= op)
            {
                if(last_op_flag)
                {
                    if('-' == last_op)
                    {
                        ret -= cur;
                        cur = 0;
                        flag = false;
                    }
                    else if('+' == last_op)
                    {
                        ret += cur;
                        cur = 0;
                        flag = false;
                    }
                }

                last_op_flag = false;
                if(!flag)
                {
                    cur = static_cast<long long> (op - '0');
                    flag = true;
                }
                else
                {
                    cur = static_cast<long long> ((op - '0') * pow(10, getDigits(cur))) + cur;
                }
            }
            else if('+' == op)
            {
                if(last_op_flag && last_op == '-')
                {
                    last_op = '-';
                }
                else
                {
                    last_op = op;
                }
                last_op_flag = true;
            }
            else if('-' == op)
            {
                if(last_op_flag && last_op == '-')
                {
                    last_op = '+';
                }
                else
                {
                    last_op = op;
                }
                last_op_flag = true;
            }
        }
        if(last_op_flag && '-' == last_op)
        {
            ret -= cur;
        }
        else
        {
            ret += cur;
        }
    }

    int calculate(string s) {
        int len = s.length();
        if(0 == len)
        {
            return 0;
        }

        long long ret = 0;
        for(int i = 0; i < len; ++i)
        {
            if(')' == s[i]) // pop current sub equation
            {
                long long curr = 0;
                if(st.empty())
                {
                    return 0;
                }
                handleParentheses(curr);
                bool flag = false;
                if(curr < 0)
                {
                    curr = 0 - curr;
                    flag = true;
                }
                stack<char> tmp;
                do
                {
                    int x = curr % 10;
                    curr /= 10;
                    tmp.push('0' + x);
                } while (0 != curr);

                if(flag)
                {
                    tmp.push('-');
                }

                while(!tmp.empty())
                {
                    st.push(tmp.top());
                    tmp.pop();
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        handleParentheses(ret);
        return ret;
    }
};

int main()
{
    //string input = "(1+(4+5+2)-3)+(6+8)";
    //string input = "2147483647";
    string input = "(5-(1+(5)))";
    Solution sol;
    int result = sol.calculate(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
