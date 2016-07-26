#include "../include/header.h"


/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

class Solution {
public:
    vector<string> mRet;

    bool checkDotsAfter(int pos, int len, int dots, string s)
    {
        if(pos > len - 1)
        {
            return false;
        }

        int digits = len - pos; 
        if(digits > dots && digits <= 3 * (dots + 1))
        {
            return true;
        }
        //cout << "checkAfter false: " << pos << ", " << dots << endl;
        return false;
    }

    bool checkDotsCurrent(string s)
    {
        if('0' == s[0] && s.length() > 1)
        {
            return false;
        }

        int value = stoi(s);
        if(0 <= value && 255 >= value)
        {
            return true;
        }
        //cout << "checkCurrent false: " << s << endl;
        return false;
    }

    void solve(int start, int len, int dots, string& cur, string s)
    {
        //cout << "Got: " << start << endl;
        if(start > len - 1)
        {
            return;
        }

        if(0 == dots)
        {
            string sub = s.substr(start, len - start);
            if(checkDotsCurrent(sub))
            {
                cur += sub;
                mRet.push_back(cur);
            }
            return;
        }

        int cur_len = cur.length();
        for(int i = start; i < min(len, start + 3); ++i)
        {
            string sub = s.substr(start, i - start + 1);
            //cout << "Check: " << start << ", " << i << ", " << sub << endl;
            if(checkDotsCurrent(sub) && checkDotsAfter(i + 1, len, dots - 1, s))
            {
                string cur_s = cur + sub + ".";
                //cout << "Enter: " << i << ", " << dots << ", " << cur << endl;
                solve(i + 1, len, dots - 1, cur_s, s);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        if(4 > len || 12 < len)
        {
            return mRet;
        }

        string cur = "";
        solve(0, len, 3, cur, s);

        return mRet;
    }
};

int main()
{
    string s = "25525511135";
    Solution sol;
    vector<string> result = sol.restoreIpAddresses(s);
    printResult();
    printVector1D(result, true);

    return 0;
}
