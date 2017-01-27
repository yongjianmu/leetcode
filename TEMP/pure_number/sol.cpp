#include "../../second/include/header.h"

bool isPrime(int N)
{
    int n = static_cast<int> (sqrt(N));
    for(int i = 2; i <= n; ++i)
    {
        if(N % i == 0) return false;
    }
    return true;
}

bool pureNumber(int N)
{
    if(isPrime(N)) return true;
    int n = static_cast<int> (sqrt(N));
    for(int i = 2; i <= n; ++i)
    {
        if(!isPrime(i)) continue;
        double d = log(N) / log(i);
        if(pow(i, static_cast<int> (d)) == N) return true;
    }
    return false;
}

int main()
{
    cout << pureNumber(49) << endl;
    return 0;
}
