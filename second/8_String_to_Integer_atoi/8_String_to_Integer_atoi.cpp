// 8_String_to_Integer_atoi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../include/header.h"

/*Requirements for atoi: 
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        if (0 == len)
        {
            return 0;
        }

        int start = 0, end = len - 1;
        while (start <= end)
        {
            if (' ' == str[start])
            {
                ++start;
            }
            else if('0' > str[end] || '9' < str[end])
            {
                --end;
            }
            else
            {
                break;
            }
        }
        if (start > end)
        {
            return 0;
        }

        long long ret = 0;
        bool minus = false;

        if ('-' == str[start])
        {
            minus = true;
            ++start;
        }
        else if ('+' == str[start])
        {
            ++start;
        }

        for (int i = start; i <= end; ++i)
        {
            if ('0' > str[i] || '9' < str[i])
            {
                break;
            }

            ret = ret * 10 + (str[i] - '0');
            if (INT_MAX < ret)
            {
                if (minus)
                {
                    return INT_MIN;
                }
                else
                {
                    return INT_MAX;
                }   
            }
        }

        if (minus)
        {
            ret = -ret;
        }
        return static_cast<int> (ret);
    }
};

int main()
{
    string str = "2147483648";
    Solution sol;
    int result = sol.myAtoi(str);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}

