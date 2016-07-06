#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        while(0 != n)
        {
            int value = (n - 1) % 26;
            n = (n - 1) / 26;

            string tmp;
            stringstream ss;
            ss << static_cast<char> ('A' + value);
            ss >> tmp;
            ret = tmp + ret;
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    cout << sol.convertToTitle(28) << endl;
    return 0;
}
