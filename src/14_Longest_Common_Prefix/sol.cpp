#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int str_num = strs.size();
        int len = 0;
        char curr_char;
        string ret;

        if(0 == str_num)
        {
            return ret;
        }
        else if(1 == str_num)
        {
            return strs[0];
        }

        while(true)
        {
            int cnt = 0;
            bool flag = false;

            if(strs[0].length() <= len)
            {
                break;
            }
            else
            {
                ++cnt;
                curr_char = strs[0][len];
            }

            for(int i = 1; i < str_num; ++i)
            {
                if(strs[i].length() <= len)
                {
                    flag = true;
                    break;
                }
                else
                {
                    if(curr_char == strs[i][len])
                    {
                        ++cnt;
                    }
                }
            }


            if(cnt == str_num)
            {
                ret.insert(len, 1, curr_char);
            }
            else
            {
                break;
            }

            ++len;
        }

        return ret;
    }
};

int main()
{
    Solution sol;
    vector<string> vec;
    vec.push_back("abcdefg");
    vec.push_back("abcdaa");
    vec.push_back("abcaa");

    cout << "Longest Prefix: " << sol.longestCommonPrefix(vec) << endl;

    return 0;
}
