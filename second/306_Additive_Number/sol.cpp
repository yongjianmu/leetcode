#include "../include/header.h"

/*
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
*/

class Solution {
public:

    bool solve(int start, int first, int second, int len, string num)
    {
        string str1 = num.substr(start, first - start);
        string str2 = num.substr(first, second - first);
        if((str1.length() > 1 && str1[0] == '0') || (str2.length() > 1 && str2[0] == '0'))
        {
            return false;
        }

        long long add1 = stol(str1), add2 = stol(str2);
        long long sum = add1 + add2;
        string tmp_ret = num.substr(second, len - second);
        if(tmp_ret.length() > 1 && tmp_ret[0] == '0')
        {
            return false;
        }

        //cout << start << ", " << first << ", " << second << ", " << stol(tmp_ret) << endl;
        if(sum == stol(tmp_ret))
        {
            return true;
        }

        int max_len = max(first - start, second - first);
        if(second + max_len <= len)
        {
            tmp_ret = num.substr(second, max_len);
            if(sum == stol(tmp_ret))
            {
                if(solve(first, second, second + max_len, len, num))
                {
                    return true;
                }
            }

            if(second + max_len + 1 <= len)
            {
                tmp_ret = num.substr(second, max_len + 1);
                if(sum == stol(tmp_ret))
                {
                    if(solve(first, second, second + max_len + 1, len, num))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool isAdditiveNumber(string num) {
        int len = num.length();
        if(3 > len)
        {
            return false;
        }

        for(int i = 1; i < len; ++i)
        {
            for(int j = i + 1; j < len; ++j)
            {
                if(solve(0, i, j, len, num))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    string input = "1203";
    Solution sol;
    bool result = sol.isAdditiveNumber(input);
    printResult();
    cout << result << endl;

    return 0;
}
