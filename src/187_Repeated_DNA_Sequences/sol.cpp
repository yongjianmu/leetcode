#include "../include/header.h"


/*
Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

    Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

    Return:
    ["AAAAACCCCC", "CCCCCAAAAA"].
*/


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        int size = s.length();
        if(10 >= size)
        {
            return ret;
        }

        unordered_map<string, int> mp;
        for(int i = 0; i < size - 9; ++i)
        {
            string sub = s.substr(i, 10);
            if(1 == mp[sub])
            {
                ret.push_back(sub);
            }
            ++mp[sub];
        }
        return ret;
    }
};

int main()
{
    string input = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution sol;
    vector<string> result = sol.findRepeatedDnaSequences(input);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << endl;
    }
    return 0;
}
