#include "../include/header.h"

/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int cnt = 0;
        while(m != n)
        {
            m >>= 1;
            n >>= 1;
            ++cnt;
        }
        return m << cnt;
    }
};

int main()
{
    int m = 5;
    int n = 7;
    Solution sol;
    int result = sol.rangeBitwiseAnd(m, n);
    cout << result << endl;
    return 0;
}
