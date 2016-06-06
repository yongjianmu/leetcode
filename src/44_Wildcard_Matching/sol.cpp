#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

    bool isMatch2(string s, string p, bool isStar) {
        int len_s = s.length();
        int len_p = p.length();
        if(0 == len_s && 0 == len_p)
        {
            return true;
        }

        if(0 == len_s && 0 != len_p)
        {
            if('*' != p[0])
            {
                return false;
            }
        }

        if(0 != len_s && 0 == len_p)
        {
            return isStar? true : false;
        }

        if('?' == p[0] || (s[0] == p[0]))
        {
            if(!isStar)
            {
                return isMatch2(s.substr(1, len_s - 1), p.substr(1, len_p - 1), false);
            }
            else
            {
                if(!isMatch2(s.substr(1, len_s - 1), p.substr(1, len_p - 1), false))
                {
                    for(int i = 1; i < len_s; ++i)
                    {
                        if(s[i] == p[0])
                        {
                            if(!isMatch2(s.substr(i, len_s - i), p, true))
                            {
                                continue;
                            }
                            else
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }

        if('*' == p[0])
        {
            return isMatch2(s, p.substr(1, len_p - 1), true);
        }

        if(s[0] != p[0])
        {
            if(isStar)
            {
                return isMatch2(s.substr(1, len_s - 1), p, true);
            }
        }

        return false;
    }

    bool isMatch(string s, string p) {
        return isMatch2(s, p, false);
    }
};

int main()
{
    string s = "abefcdgiescdfimde";
    string p = "ab*cd?i*de";
    Solution sol;
    cout << sol.isMatch(s, p) << endl;

    return 0;
}
