#include "../../second/include/header.h"

void printStr(string s)
{
    string temp;
    stringstream ss(s);
    while(getline(ss, temp))
    {
        cout << temp << endl;
    }
}

int main()
{
    string input = "123\n456\n789";
    printStr(input);

    return 0;
}
