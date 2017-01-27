#include <iostream>
using namespace std;

// Answer 001

int main()
{
    int a = 5, b = 0;
    int &r = a;
    cout << r << endl;
    r = b++;
    cout << r << endl;
    cout << a << r << b << endl;
    return 0;
}
