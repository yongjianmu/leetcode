#include "../include/header.h"


/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while(true)
        {
            if(1 == n)
            {
                ++ret;
                break;
            }

            if(1 == n % 2)
            {
                ++ret;
            }

            n /= 2;
        }

        return ret;
    }
};

int main()
{
    uint32_t input = 11;
    Solution sol;
    int result = sol.hammingWeight(input);
    cout << result << endl;

    return 0;
}
