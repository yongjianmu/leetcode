#include "../include/header.h"

/*
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
*/

class Solution {
public:
    bool isUgly(int num) {
        if(0 == num)
        {
            return false;
        }

        if(1 == num)
        {
            return true;
        }

        if(0 == num % 2)
        {
            return isUgly(num / 2);
        }

        if(0 == num % 3)
        {
            return isUgly(num / 3);
        }

        if(0 == num % 5)
        {
            return isUgly(num / 5);
        }

        return false;
    }
};

int main()
{
    int num = 14;
    Solution sol;
    cout << sol.isUgly(num) << endl;

    return 0;
}
