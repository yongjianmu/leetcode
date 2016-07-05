#include "../include/header.h"

/*
Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*/

int gNumber = 0;
bool gFlag = false;
int gRandom = 0;

bool isBadVersion(int version)
{
    if(!gFlag)
    {
        default_random_engine generator;
        uniform_int_distribution<int> distribution(1, gNumber);
        gRandom = distribution(generator);
        cout << "Random: " << gRandom << endl;
        gFlag = true;
    }

    //return (gRandom <= version);
    return 50 <= version;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        while(start < end)
        {
            int mid = start + ((end - start) >> 1);
            cout << start << ", " << end << ", " << mid << endl;
            if (isBadVersion(mid))
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        return start;
    }
};

int main()
{
    gNumber = 100;
    Solution sol;
    int result = sol.firstBadVersion(gNumber);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}

