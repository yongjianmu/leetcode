#include "../include/header.h"

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        int n = num.size(), keep = n - k;
        for (char c : num) {
            while (k && res.size() && res.back() > c) {
                res.pop_back();
                --k;
            }
            res.push_back(c);
        }
        res.resize(keep);
        while (!res.empty() && res[0] == '0') res.erase(res.begin());
        return res.empty() ? "0" : res;
    }
};

int main()
{
    string input = "1432219";
    int k = 3;

    Solution sol;
    string result = sol.removeKdigits(input, k);
    printResult();
    cout << result << endl;

    return 0;
}
