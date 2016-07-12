#include "../include/header.h"


/*
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example1:
a = 2
b = [3]

Result: 8



Example2:
a = 2
b = [1,0]

Result: 1024
*/

class Solution {
public:
    int mod = 1337;
    /*
    int superPow(int a, vector<int>& b) {
        long long ret = 1;
        int ref = 1337;
        for (auto riter = b.rbegin(); riter != b.rend(); ++riter)
        {
            ret = ((ret % ref) * static_cast<long long> (pow(a, *riter))) % ref;
            a = static_cast<long long> (pow(a, 10)) % ref;
        }
        return static_cast<int> (ret);
    }
    */

    int superPow(int a, vector<int>& b) {
        int n = b.size();
        int ans = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans = ans * quick_pow(a, b[i]) % mod;
            a = quick_pow(a, 10);
        }
        return ans;
    }
    inline int quick_pow(int a, int b) {
        int ans = 1;
        a %= mod;
        while (b > 0) {
            if (b & 1) ans = ans * a % mod;
            a = a * a %mod;
            b >>= 1;
        }
        return ans;
    }
};

int main()
{
    int a = 2147483647;
    vector<int> vec = {2, 0, 0};
    Solution sol;
    int result = sol.superPow(a, vec);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}