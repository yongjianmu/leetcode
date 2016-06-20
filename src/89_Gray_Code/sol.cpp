#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


/*
00 - 0
01 - 1
11 - 3
10 - 2
*/

class Solution {
public:

    vector<int> grayCode(int n) {
        vector<int> ret;
        int len = pow(2, n);
        char* arr = new char[n];
        memset(arr, '0', n);
        unordered_map<string, bool> mp;

        ret.push_back(0);
        string s(arr);
        mp[s] = true;

        int i = 1;
        while(i++ < len)
        {
            for(int j = n - 1; j >= 0; --j)
            {
                arr[j] = arr[j] == '1' ? '0' : '1';
                string b(arr);
                if(mp.find(b) == mp.end())
                {
                    mp[b] = true;
                    int tmp = 0;
                    for(int k = 0; k < b.length(); ++k)
                    {
                        tmp += (b[k] - '0') << k;
                    }
                    ret.push_back(tmp);
                    break;
                }
                else
                {
                    arr[j] = arr[j] == '1' ? '0' : '1';
                }
            }
        }

        delete [] arr;
        return ret;
    }
};

int main()
{
    int n = 1;
    Solution sol;
    vector<int> result = sol.grayCode(n);
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ", ";
    }
    cout << endl;

    return 0;
}
