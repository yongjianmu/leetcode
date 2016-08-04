#include "../include/header.h"


class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        while(0 < n)
        {
            ret += n / 5;
            n /= 5;
        }

        return ret;
    }
};

int main()
{
    int n = 30;
    Solution sol;
    int result = sol.trailingZeroes(n);
    printResult();
    cout << result << endl;

    return 0;
}
