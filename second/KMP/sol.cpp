#include "../include/header.h"

int KMP(string s)
{
    int len = s.length();
    vector<int> f(len + 1, 0);
    for(int i = 1; i < len; ++i)
    {
        int j = f[i];
        while(j && s[i] != s[j]) j = f[j];
        f[i + 1] = s[i] == s[j] ? j + 1 : 0;
    }
    cout << s << ", " << f[len] << endl;
    return f[len];
}

bool comp(string s, string t, int pos, int lenS, int lenT, int& retPos)
{
    int ret = true;
    int startS = pos, startT = 0;
    while(startT < lenT)
    {
        if(s[startS++] != t[startT++])
        {
            ret = false;
            break;
        }
    }

    if(ret) return ret;

    retPos = startS - KMP(s.substr(pos, startS - pos));
    return ret;
}

int stringFind(string s, string t)
{
    int ret = -1;
    int lenS = s.length(), lenT = t.length();
    if(lenS < lenT || 0 == lenS || 0 == lenT) return -1;

    int pos = 0;
    while(pos <= lenS - lenT)
    {
        if(s[pos] == t[0])
        {
            int nextPos = 0;
            if(comp(s, t, pos, lenS, lenT, nextPos))
            {
                ret = pos;
                break;
            }

            pos = nextPos;
            continue;
        }
        ++pos;
    }
    return ret;
}

int main()
{
    string s = "aefaeaeaefgeg";
    string t = "aefg";
    int result = stringFind(s, t);
    printResult();
    cout << result << endl;

    return 0;
}
