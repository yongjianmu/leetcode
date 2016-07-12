#include "../include/header.h"

class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 1;
        int end = num;

        // Binary search
        while (end >= start)
        {
            long long mid = (start + end) >> 1;
            cout << mid << endl;
            long long product = mid * mid;
            if (product == num)
            {
                return true;
            }
            else if (product < num)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    //int num = 2147483647;
    int num = 1;
    Solution sol;
    bool result = sol.isPerfectSquare(num);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}