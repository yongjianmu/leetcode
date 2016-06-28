#include <string>
#include <sstream>
#include <iostream>

using namespace std;

/*
For example,
    Given s = "the sky is blue",
    return "blue is sky the".
*/

class Solution {
public:
    void reverseWords(string &s) {
        int len = s.size();
        int pos = 0, cnt = 0;
        string::iterator iter;

        for(cnt = 0; cnt < s.size(); ++cnt)
        {
            if(' ' == s[cnt])
            {
                pos = cnt;
            }
        }

        // The start pos of the last word
        if(0 == pos)
        {
            if(1 == len)
            {
                s.erase(pos, len);
            }
            return;
        }

        int cur_len = 1;
        s.erase(pos, 1);
        for(cnt = pos - 1; cnt >= 0; --cnt)
        {
            if(0 == cnt)
            {
                string sub = s.substr(cnt, cur_len);
                s.erase(cnt, cur_len);
                sub = " " + sub;
                s += sub;
                break;
            }

            if(' ' == s[cnt])
            {
                string sub = s.substr(cnt + 1, cur_len - 1);
                s.erase(cnt, cur_len);
                sub = " " + sub;
                s += sub;
                cur_len = 1;
            }
            else
            {
                ++cur_len;
            }
        }
    }
};

int main()
{
    string input = "the sky is blue";
    Solution sol;
    sol.reverseWords(input);
    cout << "#### Result ####" << endl;
    cout << input << endl;
    return 0;
}
