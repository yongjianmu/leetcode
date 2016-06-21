#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


/*
For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

class Solution {
public:
    vector<string> mRet;

    bool isValid(string curr)
    {
        if(curr.length() > 3)
        {
            return false;
        }

        int num = 0;
        for(int i = 0; i < curr.length(); ++i)
        {
            if(i > 0 && 0 == curr[0])
            {
                return false;
            }
            num = num * 10 + curr[i];
        }

        return num <= 255;
    }

    void solve(int pos, int dot, string curr, string s)
    {
        if(3 < dot)
        {
            return;
        }

        if(3 == dot)
        {
            if(pos > s.length() - 1)
            {
                return;
            }

            string sub = s.substr(pos, s.length() - 1);
            if(isValid(sub))
            {
                mRet.push_back(curr + sub);
            }
        }

        int step = 3 < s.length() - 1 - pos ? 3 : s.length() - 1 - pos;
        for(int i = pos; i <= step; ++i)
        {
            string sub = s.substr(pos, i);
            cout << sub << endl;
            cout << dot << endl;
            cout << curr << endl;
            if(isValid(sub))
            {
                solve(i, dot + 1, sub + ".", s);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        if(4 > len || 12 < len)
        {
            return mRet;
        }

        solve(0, 0, "", s);

        return mRet;
    }
};

int main()
{
    string input = "25525511135";
    Solution sol;
    vector<string> result = sol.restoreIpAddresses(input);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ", ";
    }
    cout << endl;
    return 0;
}
