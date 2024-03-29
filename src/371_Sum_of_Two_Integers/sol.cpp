#include "../include/header.h"


class Solution {
public:

    int getSum(int a, int b) {
        int ans = 0, carry = 0;
        for (int i = 0; i < 32; a >>= 1, b >>= 1, i++) {
            int lower_a = a & 1, lower_b = b & 1;
            ans |= (lower_a ^ lower_b ^ carry) << i;
            carry = (carry & lower_a) | (carry & lower_b) | (lower_a & lower_b);
        }
        return ans;

    }
};

int main()
{
    int a = 5;
    int b = 5;
    Solution sol;
    int result = sol.getSum(a, b);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}