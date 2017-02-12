#include "../../second/include/header.h"
#include "Poco/HashMap.h"
using Poco::HashMap;

// Compile: g++ -o sol sol.cpp -std=c++11 -I/usr/local/Cellar/poco/1.7.2/include

int main()
{
    HashMap<int, int> mp;
    mp[1] = 1;
    return 0;
}
