#include "../include/header.h"

/*
"112358" is an additive number because the digits can form an additive sequence : 1, 1, 2, 3, 5, 8.
1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is : 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
*/


class Solution {
public:
    bool solve(long long num1, long long num2, string str)
    {
        long long sum = num1 + num2;
        string tmp;
        stringstream ss;
        ss << sum;
        ss >> tmp;

        int s_size = str.size();
        int t_size = tmp.size();
        if (s_size < t_size)
        {
            return false;
        }
        else if (s_size == t_size)
        {
            return str == tmp;
        }
        else
        {
            string sub = str.substr(0, t_size);
            if (sub == tmp)
            {
                return solve(num2, sum, str.substr(t_size, s_size - t_size));
            }
        }
        return false;
    }

    bool isAdditiveNumber(string num) {
        int len = num.length();
        if (3 > len)
        {
            return false;
        }

        for (int i = 0; i < len / 2; ++i) // try first num
        {
            string str1 = num.substr(0, i + 1);
            if ('0' == str1[0] && str1.length() != 1)
            {
                break;
            }
            long long num1 = stol(str1);
            for (int j = i + 1; j < len / 2 + i + 1; ++j) // try second num
            {
                string str2 = num.substr(i + 1, j - i);
                if ('0' == str2[0] && str2.length() != 1)
                {
                    continue;
                }
                long long num2 = stol(str2);
                //cout << num1 << ", " << num2 << ", " << num.substr(j + 1, len - j - 1) << endl;
                if (solve(num1, num2, num.substr(j + 1, len - j - 1)))
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
    string input = "11235813213455890144";
    Solution sol;
    bool result = sol.isAdditiveNumber(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}