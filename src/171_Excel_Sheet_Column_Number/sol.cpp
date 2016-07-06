#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


class Solution {
public:
    int convertToNumber(string s) {
        int ret = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            int value = s[i] - 'A' + 1;
            ret = ret * 26 + value;
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    cout << sol.convertToNumber("AB") << endl;
    return 0;
}
