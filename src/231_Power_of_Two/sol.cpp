#include "../include/header.h"

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(0 >= n)
        {
            return false;
        }

        int cnt = 0;
        while(0 != n)
        {
            if(1 == (n & 0x1))
            {
                ++cnt;
            }
            n >>= 1;
        }

        return 1 == cnt;
    }
};

int main()
{
    int n = 128;
    Solution sol;
    bool result = sol.isPowerOfTwo(n);
    cout << result << endl;

    return 0;
}
