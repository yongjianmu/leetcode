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

int pow_rec(int a, int b)
{
    if(0 == b) return 1;
    
    if(b & 1) return (a * pow_rec(a * a, b >> 1));
    return (pow_rec(a * a, b >> 1));
}

int main()
{
    int a = 2, b = 10;
    cout << quick_pow(a, b) << endl;
    cout << pow_rec(a, b) << endl;
    return 0;
}
