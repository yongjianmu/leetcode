#include "../include/header.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        if(0 == len1 || 0 == len2 || "0" == num1 || "0" == num2)
        {
            return "0";
        }

        vector<int> res(len1 + len2, 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for(int i = 0; i < len1; ++i)
        {
            for(int j = 0, id = i; j < len2; ++j)
            {
                res[id++] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        int carry = 0;
        for(int i = 0; i < len1 + len2; ++i)
        {
            int temp = res[i];
            res[i] = (temp + carry) % 10;
            carry = (temp + carry) / 10;
        }

        string ret(len1 + len2, '0');
        for(int i = len1 + len2 - 1, k = 0; i >= 0; --i)
        {
            ret[k++] = '0' + res[i];
        }
        int id = ret.find_first_not_of('0');
        return ret.substr(id);
    }
};

int main() {
    string input1 = "9";
    string input2 = "9";
    Solution sol;
    string result = sol.multiply(input1, input2);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}