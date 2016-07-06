#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) 
    {
        if(p.empty())
        {
            return s.empty(); 
        }

        if('*' == p[1])
        {
            while(!s.empty() && (p[0] == s[0] || '.' == p[0]))
            {
                if(isMatch(s, p.substr(2, p.size() - 2)))
                {
                    return true;
                }
                s.erase(0, 1);
            }
            return isMatch(s, p.substr(2, p.size() - 2));
        }
        else
        {
            if((p[0] == s[0] || p[0] == '.') && !s.empty())
            {
                return isMatch(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
            }
            return false;
        }
    }
};

int main()
{
    string s = "aab";
    string p = "c*a*b";

    Solution sol;
    cout << sol.isMatch(s, p) << endl;

    return 0;
}
