#include "../include/header.h"

/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ret;
        if(0 == n)
        {
            return 0;
        }
        ret.push_back(1);
        if(1 == n)
        {
            return 1;
        }

        int size = primes.size();
        vector<int> base(size, 0);
        while(ret.size() < n)
        {
            int cur = INT_MAX;
            for(int j = 0; j < size; ++j)
            {
                cur = min(cur, ret[base[j]] * primes[j]);
            }

            ret.push_back(cur);

            for(int j = 0; j < size; ++j)
            {
                if(ret.back() == ret[base[j]] * primes[j])
                {
                    ++base[j];
                }
            }
        }

        return ret.back();
    }
};

int main()
{
    vector<int> primes = {2, 7, 13, 19};
    int n = 12;
    Solution sol;
    int result = sol.nthSuperUglyNumber(n, primes);
    printResult();
    cout << result << endl;

    return 0;
}
