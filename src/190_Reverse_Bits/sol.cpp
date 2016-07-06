#include "../include/header.h"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        int cnt = 0;
        while(0 != n)
        {
            ret = (ret << 1) + (n & 0x1);
            n >>= 1;
            ++cnt;
        }

        return ret << 32 - cnt;
    }
};

int main()
{
    uint32_t input = 43261596;
    //uint32_t input = 8;
    Solution sol;
    uint32_t result = sol.reverseBits(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
