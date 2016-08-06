#include "../include/header.h"


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(0 == n)
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

            if(1 < cnt)
            {
                return false;
            }

            n >>= 1;
        }

        return true;
    }
};

int main()
{
    int n = 3;
    Solution sol;
    bool result = sol.isPowerOfTwo(n);
    printResult();
    cout << result << endl;

    return 0;
}
