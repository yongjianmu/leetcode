#include "../include/header.h"

int quick_pow(int a, int b) 
{
    int ans = 1;
    while (b > 0) 
    {
        if (b & 1)
        {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }

    return ans;
}

int main()
{
    int a = 2, b = 10;
    cout << quick_pow(a, b) << endl;
    return 0;
}
