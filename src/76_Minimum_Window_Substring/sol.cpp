#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

#include <string.h>

using namespace std;

/*
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".
*/

class Solution {
public:
    string minWindow(string s, string t) {
        string ret = "";
        int s_size = s.length();
        int t_size = t.length();

        if(0 == s_size || s_size < t_size)
        {
            return ret;
        }

        unordered_map<char, bool> t_map;
        string::iterator str_iter;
        for(str_iter = t.begin(); str_iter != t.end(); ++str_iter)
        {
            t_map[*str_iter] = true;
        }

        unordered_map<char, bool>* s_map = new unordered_map<char, bool>[s_size];
        vector<int> pos;
        vector<int> len;

        for(int i = 0; i < s_size; ++i)
        {
            for(int j = 0; j < pos.size(); ++j)
            {
                if(t_size > s_map[pos[j]].size())
                {
                    if(true == t_map[s[i]])
                    {
                        s_map[pos[j]][s[i]] = true;
                    }
                    ++len[j];
                }

            }

            if(true == t_map[s[i]])
            {
                pos.push_back(i);
                len.push_back(1);
                s_map[i][s[i]] = true;
            }

        }

        int min_len = s_size + 1;
        int start_pos = -1;
        for(int i = 0; i < pos.size(); ++i)
        {
            if(t_size == s_map[pos[i]].size())
            {
                if(min_len > len[i])
                {
                    start_pos = pos[i];
                    min_len = len[i];
                }
            }
        }

        if(-1 != start_pos)
        {
            ret = s.substr(start_pos, min_len);
        }

        delete [] s_map;

        return ret;
    }
};

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution sol;
    cout << sol.minWindow(s, t) << endl;
    return 0;
}
