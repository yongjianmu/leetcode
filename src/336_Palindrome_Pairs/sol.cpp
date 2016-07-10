#include "../include/header.h"


/*
Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]


Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
*/

class Solution {
public:
    bool isPalindrome(string str)
    {
        int len = str.length();
        if(1 >= len)
        {
            return true;
        }

        int start = 0, end = len - 1;
        while(start <= end)
        {
            if(str[start++] != str[end--])
            {
                return false;
            }
        }
        return true;
    }

    vector<vector<int> > palindromePairs(vector<string>& words) {
        vector<vector<int> > ret;
        int size = words.size();
        if(0 == size)
        {
            return ret;
        }
        return ret;
    }
};

int main()
{
    vector<string> input = {"bat", "tab", "cat"};
    Solution sol;
    vector<vector<int> > result = sol.palindromePairs(input);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        for(int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << ", ";
        }
        cout << endl;
    }		

    return 0;
}
