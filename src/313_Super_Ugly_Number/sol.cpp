#include "../include/header.h"

/*
Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
*/


class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> nums(n, 0);
        nums[0] = 1;
        vector<int> index(primes.size(), 0);
        int cnt = 1;

        while(cnt < n)
        {
            int min_value = INT_MAX;
            for(int i = 0; i < primes.size(); ++i)
            {
                min_value = min(min_value, nums[index[i]] * primes[i]);
            }

            for(int i = 0; i < primes.size(); ++i)
            {
                if(nums[index[i]] * primes[i] == min_value)
                {
                    ++index[i];
                }
            }
            nums[cnt++] = min_value;
        }
        return nums[n - 1];
    }
};
