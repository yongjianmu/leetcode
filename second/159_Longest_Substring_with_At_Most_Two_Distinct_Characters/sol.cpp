#include "../include/header.h"

/*
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.
*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int len = s.length();
        if(2 >= len)
        {
            return len;
        }
        
        unordered_map<int, int> ump;
        int cur = 0, ret = 0;
        for(int i = 0; i < len; ++i)
        {
            if(ump.find(s[i]) != ump.end())
            {
                ump[s[i]] = i;
                ++cur;
            }
            else
            {
                if(ump.size() < 2)
                {
                    ump[s[i]] = i;
                    ++cur;
                }
                else
                {
                    int pos = 0;
                    auto iter = ump.begin();
                    for(; iter != ump.end(); ++iter)
                    {
                        if(iter->first != s[i - 1])
                        {
                            pos = iter->second;
                            break;
                        }
                    }
                    ump.erase(iter);
                    ump[s[i]] = i;
                    cur = i - pos;
                }
            }
            ret = max(ret, cur);
        }
        return ret;
    }
};

int main()
{
    string input = "ecececebabababababab";
    Solution sol;
    int result = sol.lengthOfLongestSubstringTwoDistinct(input);
    printResult();
    cout << result << endl;

    return 0;
}
