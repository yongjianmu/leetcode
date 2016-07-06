#include <string>
#include <iostream>

using namespace std;

/*
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

class Solution {
public:
    int calString(int pos, string s, int sum, bool flag)
    {
        if(pos > s.length() - 1)
        {
            return sum;
        }

        int ret = 0;
        if(s[pos] < '1' || s[pos] > '9' || !flag)
        {
            flag = false;
            return 0;
        }

        if((((s[pos] == '2' && s[pos + 1] < '7') || s[pos] == '1') && s[pos + 1] != '0') && pos < s.length() - 1)
        {
            if(pos < s.length() - 2 && s[pos + 2] == '0')
            {
                ret = calString(pos + 1, s, sum, flag);
            }
            else
            {
                ret = calString(pos + 1, s, sum, flag) + calString(pos + 2, s, sum, flag);
            }
        }
        else
        {
            if((s[pos] == '1' || s[pos] == '2') && s[pos + 1] == '0' && pos < s.length() - 1)
            {
                ret = calString(pos + 2, s, sum, flag);
            }
            else
            {
                ret = calString(pos + 1, s, sum, flag);
            }
        }

        return ret;
    }

    int numDecodings(string s) {
        if(s.length() == 0)
        {
            return 0;
        }

        if(s[0] < '1' || s[0] > '9')
        {
            return 0;
        }

        return calString(0, s, 1, true);
    }
};

int main()
{
    string input = "230";
    Solution sol;
    cout << sol.numDecodings(input) << endl;
    return 0;
}
