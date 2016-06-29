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
        stack<int> five;
        stack<int> two;
        cout << five.max_size() << endl;

        while(0 != n)
        {
            if(0 == n % 10)
            {
                tNumber num = divide(n);
                ret += num.zeros;

                if(0 == num.reminder % 2)
                {
                    two.push(num.reminder);
                }
                else if(0 == num.reminder % 5)
                {
                    five.push(num.reminder);
                }
            }
            else if(0 == n % 2)
            {
                two.push(n);
            }
            else if(0 == n % 5)
            {
                five.push(n);
            }
            --n;
        }

        while(!two.empty() && !five.empty())
        {
            int t = two.top();
            int f = five.top();
            two.pop();
            five.pop();

            tNumber num = divide(t * f);
            ret += num.zeros;

            if(0 == num.reminder % 2)
            {
                two.push(num.reminder);
            }
            else if(0 == num.reminder % 5)
            {
                five.push(num.reminder);
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
