#include "../include/header.h"

/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
*/

class Solution {
public:

    /*
    void split(string& s, char delim, stack<string>& elems)
    {
        stringstream ss(s);
        string item;
        while(getline(ss, item, delim))
        {
            elems.push(item);
        }
    }

    void reverseWords(string &s) {
        for(auto iter = s.begin(); iter != s.end(); )
        {
            if(*iter != ' ')
            {
                break;
            }
            else
            {
                s.erase(iter);
            }
        }

        for(auto iter = s.rbegin(); iter != s.rend(); )
        {
            if(*iter != ' ')
            {
                break;
            }
            else
            {
                advance(iter, 1);
                s.erase(iter.base());
            }
        }

        stack<string> st;
        split(s, ' ', st);
        s = "";
        while(!st.empty())
        {
            string tmp = st.top();
            st.pop();
            if(!st.empty())
            {
                s += tmp + " ";
            }
            else
            {
                s += tmp;
            }
        }
    }
    */

    void reverseWords(string &s) {
        int len = s.length();
        if(0 == len)
        {
            return;
        }

        string t = "";
        int start = 0, end = 0;
        while(end < len)
        {
            //cout << start << ", " << end << ", " << len << endl;
            //cout << s[start] << ", " << s[end] << endl;
            if(' ' == s[start])
            {
                ++start;
                end = start;
            }
            else
            {
                if(' ' == s[end])
                {
                    start = end;
                    continue;
                }

                if(end == len - 1 || s[end + 1] == ' ')
                {
                    t = " " + s.substr(start, end - start + 1) + t;
                    ++end;
                    start = end;
                }
                else
                {
                    ++end;
                }
            }
        }

        if("" != t)
        {
            t.erase(t.begin());
        }
        s = t;
    }

};

int main()
{
    string s = "   one.   +two three?   ~four   !five- ";
    //string s = "the sky is blue";
    //string s = "  a    ";
    Solution sol;
    sol.reverseWords(s);
    printResult();
    cout << s << endl;

    return 0;
}
