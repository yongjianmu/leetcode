#include "../include/header.h"

/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
*/

void strSplit(string str, char delim, vector<string>& dest)
{
    stringstream ss(str);
    string item;
    while(getline(ss, item, delim))
    {
        dest.push_back(item);
    }
}

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        strSplit(str, ' ', words);
        int len = pattern.length();
        int size = words.size();
        if(len != size)
        {
            return false;
        }

        unordered_map<string, char> ump_str;
        unordered_map<char, string> ump_char;
        string cmp = "";
        for(int i = 0; i < len; ++i)
        {
            if(ump_str.find(words[i]) != ump_str.end())
            {
                cmp.push_back(ump_str[words[i]]);
            }
            else
            {
                if(ump_char.find(pattern[i]) != ump_char.end())
                {
                    return false;
                }
                ump_char[pattern[i]] = words[i];
                ump_str[words[i]] = pattern[i];
                cmp.push_back(pattern[i]);
            }
        }

        return cmp == pattern;
    }
};

int main()
{
    string pattern = "abbb";
    string str = "dog cat cat dog";
    Solution sol;
    bool result = sol.wordPattern(pattern, str);
    printResult();
    cout << result << endl;
    
    return 0;
}
