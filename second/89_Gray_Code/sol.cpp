#include "../include/header.h"

/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
        if(0 == n)
        {
            return ret;
        }
        ret.push_back(1);
        if(1 == n)
        {
            return ret;
        }

        for(int i = 2; i <= n; ++i)
        {
            int value = pow(2, i - 1);
            vector<int> cur;
            for(auto iter = ret.rbegin(); iter != ret.rend(); ++iter)
            {
                cur.push_back(value + *iter);
            }
            ret.insert(ret.end(), cur.begin(), cur.end());
        }
        return ret;
    }
};

int main()
{
    int n = 3;
    Solution sol;
    vector<int> result = sol.grayCode(n);
    printResult();
    printVector1D(result);

    return 0;
}
