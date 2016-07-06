#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    void solve(string s, unordered_set<string>& wordDict, string last, bool& ret)
    {
        if(0 == wordDict.size())
        {
            return;
        }

        for(unordered_set<string>::iterator iter = wordDict.begin(); iter != wordDict.end(); ++iter)
        {
            if(s == last + *iter)
            {
                ret = true;
                return;
            }

            if(s.find(last + *iter) != string::npos)
            {
                string tmpstr(*iter);
                solve(s, wordDict, last + tmpstr, ret);
            }
        }
    }

    bool wordBreak(string s, unordered_set<string>& wordDict) {
        bool ret = false;
        string curr = "";
        solve(s, wordDict, curr, ret);
        return ret;
    }
};

int main()
{
    unordered_set<string> dict = {"leet", "code"};
    for(unordered_set<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter)
    {
        cout << *iter << ", ";
    }
    cout << endl;
    cout << "#### Result ####" << endl;
    string input = "leetcode";
    Solution sol;
    cout << sol.wordBreak(input, dict) << endl;
    return 0;
}
