#include "../include/header.h"


/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/


class Solution {
public:
    map<int, bool> mp;
    int ret;

    void solve(int n, int cur)
    {
        if(n < 1)
        {
            return;
        }

        if(mp.find(n) != mp.end())
        {
            ret = min(ret, cur + 1);
            return;
        }

        for(auto iter = mp.begin(); iter != mp.end(); ++iter)
        {
            if(iter->first > n)
            {
                break;
            }

            ++cur;
            solve(n - iter->first, cur);
            --cur;
        }
    }

    int numSquares(int n) {
        for(int i = 1; ; ++i)
        {
            int x = i * i;
            if(x <= n)
            {
                mp[x] = true;
            }
            else
            {
                break;
            }
        }

        ret = INT_MAX;
        solve(n, 0);
        return ret;
    }
};

int main()
{
    int n = 1;
    Solution sol;
    int result = sol.numSquares(n);
    cout << "#### Result ####" << endl;
    cout << result <<endl;

    return 0;
}
