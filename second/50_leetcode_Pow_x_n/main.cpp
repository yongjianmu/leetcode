#include "../include/header.h"

class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1.0;
        long n1 = n;
        if(n1 < 0)
        {
            n1 = -n1;
            x = 1.0 / x;
        }

        while(n1 > 0)
        {
            if((n1 & 1) == 1)
            {
                ret *= x;
            }
            x *= x;
            n1 >>= 1;
        }
        return ret;
    }
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}