#include "../include/header.h"

class Solution {
public:
    int sqrt(int x) {
        long long left = 0, right = (x / 2) + 1;
        while (left <= right) 
        {
            long long mid = (left + right) / 2;
            long long sq = mid * mid;
            if (sq == x) return mid;
            else if (sq < x) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }

    double sqrt(double x)
    {
        if(x < 1)
        {
            double left = x, right = 1;
            while(left < right)
            {
                double mid = (left + right) / 2.0;
                double sq = mid * mid;
                if(sq == x) return mid;
                else if(sq < x)
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }
            return right;
        }
        else
        {
            double left = 1, right = x / 2.0 + 1;
            while(left < right)
            {
                double mid = (left + right) / 2.0;
                double sq = mid * mid;
                if(sq == x) return mid;
                else if(sq < x)
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }
            return right;
        }
        return -1;
    }
};

int main()
{
    //double input = 0.09;
    double input = 910.00;
    Solution sol;
    double result = sol.sqrt(input);
    cout << "reference: " << sqrt(input) << endl;
    printResult();
    cout << result << endl;

    return 0;
}
