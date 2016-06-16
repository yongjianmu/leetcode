#include <vector>
#include <iostream>

using namespace std;

/*
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:

    void rec(int start, int n, int k, vector<int>& pre, vector<vector<int> >& ret)
    {
        if(pre.size() == k)
        {
            ret.push_back(pre);
            return;
        }

        for(int i = start; i <= n ; ++i)
        {
            //vector<int> vec;
            //vec.insert(vec.begin(), pre.begin(), pre.end());
            pre.push_back(i);
            rec(i + 1, n, k, pre, ret);
            pre.pop_back();
        }
    }

    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ret;
        if(k > n || 0 == n)
        {
            return ret;
        }
        
        vector<int> pre;
        rec(1, n, k, pre, ret);
        return ret;
    }
};

int main()
{
    int n = 4, k = 2;
    Solution sol;
    vector<vector<int> > result = sol.combine(n, k);
    cout << "**** Result ****" << endl;
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
