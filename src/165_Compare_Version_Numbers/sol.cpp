#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int compareVersion(string version1, string version2) {
        vector<int> ver1;
        vector<int> ver2;
        string::iterator iter;
        int curr = 0;

        for(iter = version1.begin(); iter != version1.end(); ++iter)
        {
            if('.' == *iter)
            {
                ver1.push_back(curr);
                curr = 0;
                continue;
            }
            curr = curr * 10 + (*iter - '0');
        }
        ver1.push_back(curr);

        curr = 0;
        for(iter = version2.begin(); iter != version2.end(); ++iter)
        {
            if('.' == *iter)
            {
                ver2.push_back(curr);
                curr = 0;
                continue;
            }
            curr = curr * 10 + (*iter - '0');
        }
        ver2.push_back(curr);

        int len1 = ver1.size();
        int len2 = ver2.size();
        int ret = 0;
        for(int i = 0; i < max(len1, len2); ++i)
        {
            if(i < len1 && i < len2)
            {
                if(ver1[i] < ver2[i])
                {
                    ret = -1;
                    break;
                }
                else if(ver1[i] > ver2[i])
                {
                    ret = 1;
                    break;
                }
            }
            else if(i >= len1 && i < len2)
            {
                if(0 == ver2[i])
                {
                    continue;
                }
                else
                {
                    ret = -1;
                    break;
                }
            }
            else if(i < len1 && i >= len2)
            {
                if(0 == ver1[i])
                {
                    continue;
                }
                else
                {
                    ret = 1;
                    break;
                }
            }
        }

        return ret;
    }
};

int main()
{
    string v1 = "1.11";
    string v2 = "1.11";

    Solution sol;
    cout << sol.compareVersion(v1, v2) << endl;

    return 0;
}
