#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1;
        if(0 > n)
        {
            x = 1.0 / x;
            n = - n;
        }
        
        while(0 < n)
        {
            if(n & 1)
            {
                ret *= x;
            }

            x *= x;
            n >>= 1;
        }
        
        return ret;
    }
};

int main()
{
    int x = 2, n = 4;
    Solution sol;
    cout << sol.myPow(x, n) << endl;

    return 0;
}
