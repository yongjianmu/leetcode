#include "../include/header.h"

/*
Divide two integers without using multiplication, division and mod operator.
If it is overflow, return MAX_INT.
*/

class Solution {
public:
    long long mRet;

    long long solve(long long dividend, long long divisor)
    {
        long long value = 0;
        long long reminder = 0;
        while(dividend > divisor)
        {
            value = value == 0 ? 1 : value << 1;
            divisor <<= 1;
        }

        if(dividend == divisor)
        {
            value = value == 0 ? 1 : value << 1;
        }
        else // dividend < divisor now
        {
            divisor >>= 1;
            reminder = dividend - divisor;
        }
        mRet += value;
        return reminder;
    }

    int divide(int dividend, int divisor) {
        if(0 == divisor)
        {
            return INT_MAX;
        }
        if(0 == dividend)
        {
            return 0;
        }

        bool minus_dividend = false, minus_divisor = false;
        long long d1 = dividend, d2 = divisor;
        if(0 > d1)
        {
            minus_dividend = true;
            d1 = -d1;
        }
        if(0 > d2)
        {
            minus_divisor = true;
            d2 = -d2;
        }

        mRet = 0;
        while (true)
        {
            long long reminder = solve(d1, d2);
            cout << reminder << endl;
            if(reminder < d2)
            {
                break;
            }
            d1 = reminder;
        }


        if(minus_dividend ^ minus_divisor)
        {
            mRet = -mRet;
        }

        if(mRet > INT_MAX || mRet < INT_MIN)
        {
            return INT_MAX;
        }
        return static_cast<int> (mRet);
    }
};

int main() {
    //int dividend = 16;
    int dividend = 1;
    int divisor = -1;
    Solution sol;
    int result = sol.divide(dividend, divisor);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}