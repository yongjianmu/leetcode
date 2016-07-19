#include "../include/header.h"

/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
["ate", "eat","tea"],
["nat","tan"],
["bat"]
]
*/

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ret;
        int size = strs.size();
        if(0 == size)
        {
            return ret;
        }

        unordered_map<string, int> mp;
        for(int i = 0; i < size; ++i)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if(mp.find(tmp) == mp.end())
            {
                vector<string> cur;
                cur.push_back(strs[i]);
                ret.push_back(cur);
                mp[tmp] = ret.size() - 1;
            }
            else
            {
                ret[mp[tmp]].push_back(strs[i]);
            }
        }
        return ret;
    }
};

int main() {
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution sol;
    vector<vector<string> > result = sol.groupAnagrams(input);
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