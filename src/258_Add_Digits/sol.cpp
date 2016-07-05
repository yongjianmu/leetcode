#include "../include/header.h"


/*
Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
*/


class Solution {
public:
    int addDigits(int num) {
        if(0 == num)
        {
            return 0;
        }
        else if(0 == num % 9)
        {
            return 9;
        }

        return num % 9;
    }
};
