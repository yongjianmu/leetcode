#include "../include/header.h"

/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
*/

class Solution {
public:
    bool check(string s, vector<string> words, int pos, int size, int subsize, unordered_map<string, int> mp)
    {
        int cnt = 0;
        while(cnt < size)
        {
            string substr = s.substr(pos, subsize);
            if(mp.find(substr) != mp.end() && 0 != mp[substr])
            {
                --mp[substr];
            }
            else
            {
                break;
            }
            pos += subsize;
            ++cnt;
        }
        return cnt == size;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        int len = s.length(), size = words.size();
        if(0 == size)
        {
            return ret;
        }
        int subsize = words[0].size();
        if(0 == subsize || 0 == len || len < size * subsize)
        {
            return ret;
        }

        unordered_map<string, int> mp;
        for(int i = 0; i < size; ++i)
        {
            ++mp[words[i]];
        }

        for(int i = 0; i <= len - (size * subsize); ++i)
        {
            if(check(s, words, i, size, subsize, mp))
            {
                ret.push_back(i);
            }
        }

        return ret;
    }
};


int main() {
    string input = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};
    Solution sol;
    vector<int> result = sol.findSubstring(input, words);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << endl;
    }

    return 0;
}