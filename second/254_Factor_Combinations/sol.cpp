#include "../include/header.h"

/*
Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note: 
You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Examples: 
input: 1
output: 
[]
input: 37
output: 
[]
input: 12
output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
input: 32
output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/

class Solution {
public:

    void solve(vector<vector<int> >& ret, vector<int>& vec, int n, int start)
    {
        if(1 == n)
        {
            if(1 < vec.size())
            {
                ret.push_back(vec);
            }
            return;
        }

        for(int i = start; i <= n; ++i)
        {
            if(0 == (n % i))
            {
                vec.push_back(i);
                solve(ret, vec, n / i, i);
                vec.pop_back();
            }
        }
    }

    vector<vector<int> > getFactors(int n) {
        vector<vector<int> > ret;
        if(4 > n)
        {
            return ret;
        }

        vector<int> vec;
        solve(ret, vec, n, 2);
        return ret;

    }
};

int main()
{
    Solution sol;
    vector<vector<int> > result = sol.getFactors(32);
    printResult();
    printVector2D(result);

    return 0;
}
