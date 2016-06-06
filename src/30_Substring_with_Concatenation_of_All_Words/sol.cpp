#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int> ret;
        int word_num = words.size();
        if(0 == s.length() || 0 == word_num)
        {
            return ret;
        }
        int word_len = words[0].length();
        int check_len = s.length() - word_num * word_len;
        map<string, int> dict;

        for(int i = 0; i < word_num; ++i)
        {
            ++dict[words[i]];
        }

        for(int i = 0; i <= check_len; ++i)
        {
            map<string, int> curr;
            for(int j = 0; j < word_num; ++j)
            {
                string sub_str = s.substr(i + j * word_len, word_len);
                ++curr[sub_str];
                if(dict.find(sub_str) == dict.end() || curr[sub_str] > dict[sub_str])
                {
                    goto SKIP;
                }
            }
            ret.push_back(i);
        SKIP:;
        }
        return ret;
    }
};

int main()
{
    string input = "barfoothefoobarman";
    vector<string> words;
    words.push_back("foo");
    words.push_back("bar");
    Solution sol;
    vector<int> result = sol.findSubstring(input, words);
    vector<int>::iterator iter;
    for(iter = result.begin(); iter != result.end(); ++iter)
    {
        cout << *iter << ",";
    }
    cout <<endl;

    return 0;
}
