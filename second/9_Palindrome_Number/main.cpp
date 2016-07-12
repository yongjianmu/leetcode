#include "../include/header.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if(0 == x)
        {
            return true;
        }

        long long n = x;
        if(0 > n)
        {
            return false;
        }
        long long m = n;

        long long ref = 0;
        while(0 != n)
        {
            ref = ref * 10 + (n % 10);
            n /= 10;
        }

        return ref == m;
    }
};

int main() {
    int x = -12321;
    Solution sol;
    bool result = sol.isPalindrome(x);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}