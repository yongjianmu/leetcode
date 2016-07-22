#include "../include/header.h"



/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/


class Solution {
public:
    void split(string s, char delim, stack<string> &st) 
    {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) 
        {
            st.push(item);
        }
    }

    string simplifyPath(string path) {
        string ret = "";
        int len = path.length();
        if(0 == len)
        {
            return ret;
        }

        stack<string> st;
        split(path.substr(1, len - 1), '/', st);
        int up_folder = 0;
        while(!st.empty())
        {
            string cur = st.top();
            st.pop();
            if("" == cur || "." == cur)
            {
                continue;
            }
            else if(".." == cur)
            {
                ++up_folder;
            }
            else
            {
                if(0 != up_folder)
                {
                    --up_folder;
                }
                else
                {
                    ret.insert(0, "/" + cur);
                }
            }
        }
        
        if(ret.length() == 0)
        {
            ret += "/";
        }
        return ret;
    }
};

int main()
{
    string path = "/../";
    Solution sol;
    string result = sol.simplifyPath(path);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
