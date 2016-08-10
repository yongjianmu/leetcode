#include "../include/header.h"

/*
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
*/

class Solution {
public:
    bool isUgly(int num) {
        if(0 >= num)
        {
            return false;
        }

        while(0 == num % 2)
        {
            num /= 2;
        }
        while(0 == num % 3)
        {
            num /= 3;
        }
        while(0 == num % 5)
        {
            num /= 5;
        }

        return 1 == num;
    }
};
