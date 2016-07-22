#include "../include/header.h"

class Solution {
public:
    int mySqrt(int x) {
        if(0 == x)
        {
            return 0;
        }

        long long left = 1, right = x >> 1;
        while(left < right)
        {
            long long mid = left + ((right - left) >> 1);
            long long sqr = mid * mid;
            if(sqr == x)
            {
                return mid;
            }
            else if(sqr < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        long long sqr = left * left;
        return sqr > x ? static_cast<int> (left - 1) : static_cast<int> (left);
    }
};
