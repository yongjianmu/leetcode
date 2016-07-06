/*
 * sol.cpp
 *
 *  Created on: 2016年6月25日
 *      Author: Yongjian
 */
#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

/*
   For example, given s = "aab",
   Return

   [
   ["aa","b"],
   ["a","a","b"]
   ]
   */

class Solution {
public:
    bool isValid(string str)
    {
        int len = str.length();
        if(1 >= len)
        {
            return true;
        }

        int start = 0;
        int end = len - 1;
        while(start <= end)
        {
            if(str[start++] != str[end--])
            {
                return false;
            }
        }
        return true;
    }

    void solve(vector<string> cur, int start, int end, string s, int& ret)
    {
        if(start >= end)
        {
            ret = min(ret, static_cast<int>(cur.size()));
            return;
        }

        for(int i = start; i < end; ++i)
        {
            string str = s.substr(start, i + 1 - start);
            if(isValid(str))
            {
                vector<string> vec;
                vec.insert(vec.begin(), cur.begin(), cur.end());
                vec.push_back(str);
                solve(vec, i + 1, end, s, ret);
            }
        }
    }

    int minCut(string s) {
        int ret = INT_MAX;
        vector<string> cur;
        solve(cur, 0, s.length(), s, ret);
        return ret - 1;
    }
};

int main()
{
    string s = "aab";
    Solution sol;
    cout << sol.minCut(s) << endl;
    return 0;
}





