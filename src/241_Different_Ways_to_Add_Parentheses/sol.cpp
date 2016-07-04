#include "../include/header.h"

/*
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10

Output: [-34, -14, -10, -10, 10]
*/

class Solution {
public:
    vector<int> ret;

    void solve(string input)
    {
        vector<int> op;
        for(int i = 0; i < input.length(); ++i)
        {
            if('*' == input[i] || '+' == input[i] || '-' == input[i])
            {
                op.push_back(i);
            }

        }
    }

    vector<int> diffWaysToCompute(string input) {
        solve(input);
        return ret;
    }
};


