#include "../include/header.h"

vector<string> uniqueSubString(string s)
{
    vector<string> ret;
    int len = s.length();
    if(0 == len) return ret;

    queue<string> q1, q2;
    unordered_set<string> st;

    for(int i = 0; i < len; ++i)
    {
        q2.push(string(1, s[i]));
        st.insert(string(1, s[i]));
        while(!q1.empty())
        {
            string cur = q1.front();
            q1.pop();
            cur.push_back(s[i]);
            q2.push(cur);
            st.insert(cur);
        }
        q1.swap(q2);
    }

    for(string str : st)
    {
        ret.push_back(str);
    }
    return ret;
}

int main()
{
    string s = "abcdabcd";
    vector<string> result = uniqueSubString(s);
    printResult();
    printVector1D(result, true);
    return 0;
}
