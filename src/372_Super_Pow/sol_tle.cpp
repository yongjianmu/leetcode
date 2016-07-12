#include "../include/header.h"


/*
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example1:
a = 2
b = [3]

Result: 8



Example2:
a = 2
b = [1,0]

Result: 1024
*/

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int ref = 1337;
        int x = 1;
        int aa = a;
        while (aa < ref)
        {
            aa *= a;
            ++x;
        }

        int y = 0;
        for (int i = 0; i < b.size(); ++i)
        {
            y = y * 10 + b[i];
        }
        
        if (aa == ref)
        {
            if (x <= y)
            {
                return 0;
            }
            else if (x > y)
            {
                return pow(a, y);
            }
        }

        if (x - 1 >= y)
        {
            return static_cast<int> (pow(a, y));
        }

        long long reminder = static_cast<long long> (pow(a, x)) % ref;
        reminder = (static_cast<long long> (pow(a, y - x)) * reminder) % ref;
        return static_cast<int> (reminder);
    }
};

int main()
{
    int a = 2;
    vector<int> vec = {1, 5};
    Solution sol;
    int result = sol.superPow(a, vec);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}