#include "../include/header.h"

/*
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */

class Solution {
public:
    vector<string> mRet;

    void solve(int pos, string cur, string digits, vector<vector<char> > dict)
    {

    }

    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        vector<vector<char> > dict = {
            {' '},
            {''},
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

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}