#include "../include/header.h"

/*
Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
public:
    void solve(unordered_map<int, bool>& mp, vector<vector<int> >& ret, int start, vector<int>& curr, int n, int k, int sum)
    {
        if(0 == k)
        {
            return;
        }

        if(1 == k && !mp[start] && start + sum == n)
        {
            cout << "3: " << n - sum<< endl;
            curr.push_back(n - sum);
            ret.push_back(curr);
            curr.pop_back();
            return;
        }

        for(int i = start; i <= n - sum; ++i)
        {
            cout << "2: " << i << endl;
            if(!mp[i] && sum + i  < n)
            {
                mp[i] = true;
                curr.push_back(i);
                solve(mp, ret, i + 1, curr, n, k - 1, sum + i);
                mp[i] = false;
                curr.pop_back();
            }
        }
    }

    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > ret;

        unordered_map<int, bool> mp;
        for(int i = 1; i <= 9; ++i)
        {
            mp[i] = false;
        }

        for(int i = 1; i <= n / k; ++i)
        {
            cout << "1: " << i << endl;
            mp[i] = true;
            vector<int> curr;
            curr.push_back(i);
            solve(mp, ret, i + 1, curr, n, k - 1, i);
            mp[i] = false;
            curr.pop_back();
        }

        return ret;
    }
};

int main()
{
    Solution sol;
    vector<vector<int> >result = sol.combinationSum3(3, 9);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        for(int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}
