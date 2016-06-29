#include "../include/header.h"

class Solution {
public:

    struct tNumber
    {
        int zeros;
        int reminder;
        tNumber() : zeros(0), reminder(-1) {}
    };

    tNumber divide(int n)
    {
        tNumber ret;
        while(0 == n % 10)
        {
            n /= 10;
            ++ret.zeros;
        }
        ret.reminder = n;
        return ret;
    }

    int trailingZeroes(int n) {
        int ret = 0;
        vector<int> five;
        vector<int> two;
        cout << five.max_size() << endl;

        while(0 != n)
        {
            if(0 == n % 10)
            {
                tNumber num = divide(n);
                ret += num.zeros;

                if(0 == num.reminder % 2)
                {
                    two.push_back(num.reminder);
                }
                else if(0 == num.reminder % 5)
                {
                    five.push_back(num.reminder);
                }
            }
            else if(0 == n % 2)
            {
                two.push_back(n);
            }
            else if(0 == n % 5)
            {
                five.push_back(n);
            }
            --n;
        }

        while(0 != two.size() && 0 != five.size())
        {
            int t = two[0];
            int f = five[0];
            two.erase(two.begin());
            five.erase(five.begin());

            tNumber num = divide(t * f);
            ret += num.zeros;

            if(0 == num.reminder % 2)
            {
                two.push_back(num.reminder);
            }
            else if(0 == num.reminder % 5)
            {
                five.push_back(num.reminder);
            }
        }

        return ret;
    }
};

int main()
{
    Solution sol;
    cout << sol.trailingZeroes(415) << endl;

    return 0;
}
