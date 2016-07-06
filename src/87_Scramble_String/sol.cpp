#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len_s1 = s1.length();
        int len_s2 = s2.length();

        if(0 == len_s1 && 0 == len_s2)
        {
            return true;
        }

        if(len_s1 != len_s2)
        {
            return false;
        }


    }
};
