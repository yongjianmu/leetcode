#include "../include/header.h"

/*
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:

    int solve(int cur, int n)
    {
        if(cur > n)
        {
            return 0;
        }
        else if(cur == n)
        {
            return 1;
        }
        else
        {
            return solve(cur + 1, n) + solve(cur + 2, n);
        }
    }

    int climbStairs(int n) {
        if(0 == n)
        {
            return 0;
        }
        return solve(0, n);
    }
};
