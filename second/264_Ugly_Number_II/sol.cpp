#include "../include/header.h"

/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ret(1, 1);
        int two = 0, three = 0, five = 0;
        while(ret.size() < n)
        {
            ret.push_back(min(ret[two] * 2, min(ret[three] * 3, ret[five] * 5)));
            if(ret.back() == ret[two] * 2) ++two;
            if(ret.back() == ret[three] * 3) ++three;
            if(ret.back() == ret[five] * 5) ++five;
        }

        return ret.back();
    }
};
