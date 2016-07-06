#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x)
    {
        if(0 > x)
        {
            return false;
        }

        int k = 0;
        int p = x;

        while(0 != p)
        {
            k = k * 10 + p % 10;
            p /= 10;
        }

        return x == k;
    }
};

int main()
{
    int x = 12324321;
    Solution sol;
    cout << sol.isPalindrome(x) << endl;
    return 0;
}
