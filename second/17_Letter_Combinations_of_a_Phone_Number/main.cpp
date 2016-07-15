#include "../include/header.h"

/*
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */

class Solution {
public:
    vector<string> mRet;
    int len;

    void solve(int pos, string cur, string digits, vector<vector<char> > dict)
    {
        if(pos >= len)
        {
            mRet.push_back(cur);
            return;
        }

        for(int i = 0; i < dict[digits[pos] - '0'].size(); ++i)
        {
            cur.push_back(dict[digits[pos] - '0'][i]);
            solve(pos + 1, cur, digits, dict);
            cur.pop_back();
        }
    }

    vector <string> letterCombinations(string digits) {
        len = digits.length();
        if(0 == len)
        {
            return mRet;
        }

        vector<vector<char> > dict = {
                {' '},
                {},
                {'a', 'b', 'c'},
                {'d', 'e', 'f'},
                {'g', 'h', 'i'},
                {'j', 'k', 'l'},
                {'m', 'n', 'o'},
                {'p', 'q', 'r', 's'},
                {'t', 'u', 'v'},
                {'w', 'x', 'y', 'z'}
        };

        string cur;
        solve(0, cur, digits, dict);
        return mRet;
    }
};

int main()
{
    string input = "23";
    Solution sol;
    vector<string> result = sol.letterCombinations(input);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ", ";
    }
    cout << endl;

    return 0;
}