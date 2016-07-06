#include "../include/header.h"

class Solution {
public:
    int countPrimes(int n) {
        if(2 >= n)
        {
            return 0;
        }

        vector<bool> prime(n, true);
        for(int i = 2; i < sqrt(n); ++i)
        {
            if(prime[i])
            {
                for(int j = i; j * i < n; ++j)
                {
                    prime[j * i] = false;
                }
            }
        }

        int ret = 0;
        for(int i = 2; i < n; ++i)
        {
            if(prime[i])
            {
                ++ret;
            }
        }

        return ret;
    }
};
